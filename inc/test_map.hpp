#include <iostream>
#ifdef MINE
  #include "map.hpp"
  using namespace ft;
#else
  #include <map>
  using namespace std;
#endif

template <typename C>
void print_map(C & cont) {
	for (typename C::iterator it = cont.begin(); it != cont.end(); ++it)
		std::cout << it->first << "|" << it->second << " ";
	std::cout << std::endl << "size = " << cont.size() << std::endl;
}
