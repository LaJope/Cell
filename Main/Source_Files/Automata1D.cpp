#include "Automata1D.h"
#include <cassert>
#include <string>
#include <vector>

Automata1D::Automata1D(std::string &&start_ruleSet,
                       std::vector<bool> &&start_state) {
  m_ruleSet = std::move(start_ruleSet);
  m_state = std::move(start_state);
}

void Automata1D::newState() {
  std::vector<bool> new_state(m_state.size(), false);
  for (int i = 0; i < m_state.size(); i++) {
    bool left = (i == 0) ? m_state[m_state.size() - 1] : m_state[i - 1];
    bool middle = m_state[i];
    bool right = (i == m_state.size() - 1) ? m_state[0] : m_state[i + 1];
    new_state[i] = calculateState(left, middle, right);
  }
  m_state = std::move(new_state);
}

int Automata1D::calculateState(int left, int middle, int right) {
  std::string a = std::to_string(left * 100 + middle * 10 + right);
  return m_ruleSet[7 - std::stoull(a, 0, 2)] - '0';
}

void Automata1D::set(int index, bool value) {
  assert(0 <= index && index < m_state.size() &&
         "Index must be in range [0, state.size() - 1]");
  m_state[index] = value;
}

const std::vector<bool> &Automata1D::getState() const { return m_state; }
