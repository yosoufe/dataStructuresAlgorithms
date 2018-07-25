#include <iostream>
#include <vector>
#include <random>
#include <list>

using namespace std;

int main()
{
  std::vector<int> c = {1, 2, 3};
  std::cout << "The vector holds: ";
  for(auto& el: c) std::cout << el << ' ';
  std::cout << '\n';
  c.reserve(5);
  c[4] = 10;
  std::cout << "After reserve 5: ";
  for(auto& el: c) std::cout << el << ' ';
  std::cout << '\n';
  c.push_back(4);
  std::cout << "After pushing back: ";
  for(auto& el: c) std::cout << el << ' ';
  std::cout << '\n';

  c.resize(2);
  std::cout << "After resize down to 2: ";
  for(auto& el: c) std::cout << el << ' ';
  std::cout << '\n';

  std::cout << 0%10 << ' ' << 1%10 << ' ' << 10%10 << ' ' << RAND_MAX << '\n';

  std::list<int> l;
  l.push_front(10);
  cout << (l.begin()==l.end()) << '\n';
  int& n = *l.end();
  cout << &n << '\n';


  return 0;
}
