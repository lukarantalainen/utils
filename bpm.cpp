#include <chrono>
#include <iostream>

int getInput() {
  std::string s;
  std::cin >> s;

  return s.length();
}

int calcBpm(int beats, double time) {
  return static_cast<int>(beats / (time / 60) + 0.5);
}

int main() {
  std::cout << "Input a character on every beat. please input at least 10 "
               "beats before submitting.\n";
  std::cout << "Press 'x' to start\n";
  char c;
  while (std::cin >> c) {
    if (c == 'x') {
      break;
    }
  }

  auto start{std::chrono::system_clock::now()};
  int beats{getInput()};
  auto end{std::chrono::system_clock::now()};

  double time{std::chrono::duration<double>(end - start).count()};
  std::cout << "Measurement finished with " << beats << " beats in time "
            << time << "s\n";
  std::cout << "Your BPM was " << calcBpm(beats, time);
}
