#include <iostream>
#include <queue>

using namespace std;

// queue is FIFO
// stack is FILO

int main()
{
  queue<int> qu;
  for (int i=1; i<=10; i++) qu.push(i);

  for(int i=1; i<=10; i++)
  {
    cout << qu.front()<< " ";
    qu.pop();
  }
  cout << endl;
  return 0;
}
