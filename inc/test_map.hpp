#include <iostream>
#ifdef MINE
#include "map.hpp"
using namespace ft;
#else
#include <map>
using namespace std;
#endif

using std::cout;
using std::endl;

template <typename C>
void print_map(C &c)
{
  for (typename C::iterator it = c.begin(); it != c.end(); ++it)
    cout << it->first << "|" << std::flush << it->second << " " << std::flush;
  cout << endl
       << "size = " << c.size() << endl;
}
