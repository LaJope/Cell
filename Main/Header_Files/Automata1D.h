#pragma once
#include <string>
#include <vector>

class Automata1D {
public:
  Automata1D(std::string &&start_ruleSet = "00000000",
             std::vector<bool> &&start_state = {0});

  void newState();

  void set(int index, bool value);

  const std::vector<bool> &getState() const;

private:
  std::string m_ruleSet;
  std::vector<bool> m_state;

private:
  int calculateState(int left, int middle, int right);
};
