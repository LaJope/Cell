#include "Automata2D.h"
#include "Random.h"
#include <cassert>
#include <vector>

Automata2D::Automata2D(int start_rule,
                       std::vector<std::vector<bool>> &&start_field) {
  m_rule = start_rule;
  m_field = std::move(start_field);
}

Automata2D::Automata2D(int start_rule, int rows, int columns) {
  m_rule = start_rule;
  m_field =
      std::vector<std::vector<bool>>(rows, std::vector<bool>(columns, false));
}

void Automata2D::newState() {
  std::vector<std::vector<bool>> new_field(
      m_field.size(), std::vector(m_field[0].size(), false));
  for (int row = 0; row < new_field.size(); row++)
    for (int column = 0; column < new_field[0].size(); column++) {
      int lt = m_field[(row - 1 + m_field.size()) % m_field.size()]
                      [(column - 1 + m_field[0].size()) % m_field[0].size()];
      int t = m_field[(row - 1 + m_field.size()) % m_field.size()][column];
      int rt = m_field[(row - 1 + m_field.size()) % m_field.size()]
                      [(column + 1) % m_field[0].size()];

      int lc =
          m_field[row][(column - 1 + m_field[0].size()) % m_field[0].size()];
      int rc = m_field[row][(column + 1) % m_field[0].size()];

      int lb = m_field[(row + 1) % m_field.size()]
                      [(column - 1 + m_field[0].size()) % m_field[0].size()];
      int b = m_field[(row + 1) % m_field.size()][column % m_field[0].size()];
      int rb =
          m_field[(row + 1) % m_field.size()][(column + 1) % m_field[0].size()];
      int sum = lt + t + rt + lc + rc + lb + b + rb;
      if (m_field[row][column])
        new_field[row][column] = (sum == 2 || sum == 3);
      else
        new_field[row][column] = (sum == 3);
    }
  m_field = std::move(new_field);
}

void Automata2D::set(int row, int column, bool value) {
  assert(row >= 0 && row <= m_field.size() && column >= 0 &&
         column <= m_field[0].size());
  m_field[row][column] = value;
}

void Automata2D::fillRandom() {
  int rand_count = getRandomNum(getNumRows() * getNumColumns() * 1 / 10,
                                getNumRows() * getNumColumns() * 3 / 10);
  for (int i = 0; i < rand_count; i++) {
    int rand_row = getRandomNum(0, getNumRows() - 1);
    int rand_col = getRandomNum(0, getNumColumns() - 1);
    set(rand_row, rand_col, true);
  }
}

int Automata2D::getNumRows() const { return m_field.size(); }
int Automata2D::getNumColumns() const { return m_field[0].size(); }

const bool Automata2D::getState(int row, int col) const {
  return m_field[row][col];
}
