#pragma once
#include <vector>

class Automata2D {
  public:
    Automata2D(int start_rule = 3,
        std::vector<std::vector<bool>> &&start_field = {{false}});
    Automata2D(int start_rule = 3, int rows = 1, int columns = 1);

    void newState();

    void set(int row, int column, bool value);
    void fillRandom();

    int getNumRows() const;
    int getNumColumns() const;

    const bool getState(int row, int col) const;

    friend void terminalAutomata2D();

private:
  int m_rule;
  std::vector<std::vector<bool>> m_field;

};
