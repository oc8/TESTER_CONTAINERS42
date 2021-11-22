#include "test_map.hpp"

typedef map<int, int> Map;
typedef pair<int, int> Pair;

Map basic()
{
   Map c;
   for (int i = 0; i < 5; ++i)
      c[i] = i;
   return c;
}

int test()
{
   cout << "----------> [] <----------" << endl;
   {
      Map c = ::basic();
      c[0] = c[1];
      c[2] = c[3];
      c[2] = c[0];
      c[10] = c[9];
      c[102];
      print_map<Map>(c);
   }
   cout << "----------> operators <----------" << endl;
   {
		Map c = ::basic();
		Map c2 = ::basic();
		c2[1] = c[2];
		cout << "operator==: " << (c == c2) << endl;
		cout << "operator!=: " << (c != c2) << endl;
		cout << "operator<: " << (c < c2) << endl;
		cout << "operator>: " << (c > c2) << endl;
		cout << "operator<=: " << (c <= c2) << endl;
		cout << "operator>=: " << (c >= c2) << endl;
      c2[-1] = 2;
		cout << "operator==: " << (c == c2) << endl;
		cout << "operator!=: " << (c != c2) << endl;
		cout << "operator<: " << (c < c2) << endl;
		cout << "operator>: " << (c > c2) << endl;
		cout << "operator<=: " << (c <= c2) << endl;
		cout << "operator>=: " << (c >= c2) << endl;
		c2 = c;
		cout << "operator==: " << (c == c2) << endl;
		cout << "operator!=: " << (c != c2) << endl;
		cout << "operator<: " << (c < c2) << endl;
		cout << "operator>: " << (c > c2) << endl;
		cout << "operator<=: " << (c <= c2) << endl;
		cout << "operator>=: " << (c >= c2) << endl;
      cout << endl;

	}
   cout << "----------> constructors <----------" << endl;
   {
      Map c;
      print_map<Map>(c);
      c = ::basic();
      // Map c2(c.begin(), c.end());
      // print_map<Map>(c2);
      // Map c3(c2);
      // print_map<Map>(c3);
   }
   cout << "----------> insert <----------" << endl;
   {
      Map c = ::basic();
      pair<Map::iterator, bool> r;
      print_map<Map>(c);
      r = c.insert(Pair(10000, 10000));
      c[-1] = r.first->second;
      c[-2] = r.second;
      print_map<Map>(c);
      r = c.insert(Pair(-1, -1));
      cout << "inserted: " << r.first->second << endl;
      cout << "inserted: " << c[-1] << endl;
      c[-3] = r.first->second;
      c[-4] = r.second;
      print_map<Map>(c);
   }
   cout << "----------> erase <----------" << endl;
   {
      Map c = ::basic();
      cout << "erase 1: " << c.erase(1) << endl;
      cout << "erase 2: " << c.erase(2) << endl;
      print_map<Map>(c);
      cout << "erase 0: " << c.erase(0) << endl;
      print_map<Map>(c);
      c[0] = 1000;
      c[2] = 999999;
      cout << "erase 1000: " << c.erase(1000) << endl;
      cout << "erase 2: " << c.erase(2) << endl;
      print_map<Map>(c);
   }

   cout << "----------> swap <----------" << endl;
   {
      Map c = ::basic();
      Map c2;
      c2[56] = 3;
      c2[4] = 10;
      c.swap(c2);
      print_map<Map>(c);
      print_map<Map>(c2);
   }
   cout << "----------> clear & empty <----------" << endl;
   {
      Map c = ::basic();
      cout << "empty: " << c.empty() << endl;
      print_map<Map>(c);
      c.clear();
      cout << "empty: " << c.empty() << endl;
      print_map<Map>(c);
      c[10] = 9;
      cout << "empty: " << c.empty() << endl;
      print_map<Map>(c);
      c.clear();
      print_map<Map>(c);
      c[2] = 42;
      print_map<Map>(c);
      c[50] = 20;
      print_map<Map>(c);
   }
   cout << "----------> size & max_size <----------" << endl;
   {
      Map c = Map();
      cout << "size = " << c.size() << endl;
      c[0] = 1;
      c[-1] = 2;
      cout << "size = " << c.size() << endl;
      c.clear();
      cout << "size = " << c.size() << endl;
   }
   return 0;
}
