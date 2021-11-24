#include "test_map.hpp"

/*
            10
           /  \
          5    21
         / \   / \
        2   8 15  30
       /         /  \
      1        25    42
              / \    / \
            23  27  35  84
             \    \     /
             24   29   43
                  /
                 28
*/
map<int, int> basic()
{
   map<int, int> c;
   c[10] = 10;
   c[5] = 5;
   c[21] = 21;
   c[2] = 2;
   c[8] = 8;
   c[15] = 15;
   c[30] = 30;
   c[1] = 1;
   c[25] = 25;
   c[42] = 42;
   c[23] = 23;
   c[27] = 27;
   c[35] = 35;
   c[84] = 84;
   c[24] = 24;
   c[29] = 29;
   c[28] = 28;
   c[43] = 43;
   return c;
}

int const_test();

int test()
{
   typedef map<int, int> Map;
   typedef pair<int, int> Pair;
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
      cout << "erase 2: " << c.erase(2) << endl;
      cout << "erase 1: " << c.erase(1) << endl;
      cout << "erase 0: " << c.erase(0) << endl;
      cout << "erase 25: " << c.erase(25) << endl;
      cout << "erase 42: " << c.erase(42) << endl;
      cout << "erase 30: " << c.erase(30) << endl;
      cout << "erase 27: " << c.erase(30) << endl;
      print_map<Map>(c);
      // erase last
      cout << "erase 43 (last): " << c.erase(43) << endl;
      print_map<Map>(c);
      // erase root
      cout << "erase 10 (root): " << c.erase(10) << endl;
      print_map<Map>(c);
      /* result for basic bst:
            15
           /  \
          5    21
           \    \
            8    35
                /  \
               28  84
              / \
            23  29
             \
             24
      */
      // erase root last
      c = Map();
      c[10] = 10;
      cout << "erase 10 (root last): " << c.erase(10) << endl;
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
   cout << "----------> size <----------" << endl;
   {
      Map c = Map();
      cout << "size = " << c.size() << endl;
      c[0] = 1;
      c[-1] = 2;
      cout << "size = " << c.size() << endl;
      c.clear();
      cout << "size = " << c.size() << endl;
   }
   cout << "----------> observers <----------" << endl;
   {
      Map c = ::basic();
      cout << c.key_comp()(10, 2) << endl;
      // cout << c.value_comp()(10, 2) << endl;
      c.get_allocator();
   }
   cout << "----------> find & count <----------" << endl;
   {
      Map c = ::basic();
      Map::iterator i = c.find(2);
      cout << "find 2: " << (i != c.end()) << endl;
      cout << "count 2: " << c.count(2) << endl;
      i = c.find(42);
      cout << "find 42: " << (i != c.end()) << endl;
      cout << "count 42: " << c.count(42) << endl;
      i = c.find(50);
      cout << "find 50: " << (i != c.end()) << endl;
      cout << "count 50: " << c.count(50) << endl;
      // const Map c2(c);
      // Map::const_iterator l = c2.find(2);
      // cout << "find 2: " << (l != c2.end()) << endl;
      // cout << "count 2: " << c2.count(2) << endl;
      // Map::const_iterator j = c2.find(42);
      // cout << "find 42: " << (j != c2.end()) << endl;
      // cout << "count 42: " << c2.count(42) << endl;
      // Map::const_iterator k = c2.find(50);
      // cout << "find 50: " << (k != c2.end()) << endl;
      // cout << "count 50: " << c2.count(50) << endl;
   }
   cout << "----------> bound <----------" << endl;
   {
      Map c(::basic());
      Map::iterator it = c.lower_bound(2);
      cout << "lower_bound: " << it->first << endl;
      it = c.upper_bound(2);
      cout << "upper_bound: " << it->first << endl;
   }
   const_test();
   return 0;
}

int const_test()
{
   typedef const map<int, int> Map;
   cout << "----------> operators <----------" << endl;
   {
      Map c = ::basic();
      Map c2 = ::basic();
      cout << "operator==: " << (c == c2) << endl;
      cout << "operator!=: " << (c != c2) << endl;
      cout << "operator<: " << (c < c2) << endl;
      cout << "operator>: " << (c > c2) << endl;
      cout << "operator<=: " << (c <= c2) << endl;
      cout << "operator>=: " << (c >= c2) << endl;
   }
   cout << "----------> constructors <----------" << endl;
   {
      Map c;
      print_map<Map>(c);
      // c = ::basic();
      // Map c2(c.begin(), c.end());
      // print_map<Map>(c2);
      // Map c3(c2);
      // print_map<Map>(c3);
   }
   cout << "----------> empty <----------" << endl;
   {
      Map c = ::basic();
      cout << "empty: " << c.empty() << endl;
      Map c2;
      cout << "empty: " << c2.empty() << endl;
   }
   cout << "----------> size <----------" << endl;
   {
      Map c = Map();
      cout << "size = " << c.size() << endl;
      Map c2 = ::basic();
      cout << "size = " << c.size() << endl;
   }
   cout << "----------> observers <----------" << endl;
   {
      Map c = ::basic();
      cout << c.key_comp()(10, 2) << endl;
      // cout << c.value_comp()(10, 2) << endl;
   }
   cout << "----------> find & count <----------" << endl;
   {
      Map c2(::basic());
      Map::const_iterator it = c2.find(2);
      cout << "find 2: " << (it != c2.end()) << endl;
      cout << "count 2: " << c2.count(2) << endl;
      it = c2.find(42);
      cout << "find 42: " << (it != c2.end()) << endl;
      cout << "count 42: " << c2.count(42) << endl;
      it = c2.find(50);
      cout << "find 50: " << (it != c2.end()) << endl;
      cout << "count 50: " << c2.count(50) << endl;
   }
   cout << "----------> bound <----------" << endl;
   {
      Map c(::basic());
      Map::const_iterator it = c.lower_bound(2);
      cout << "lower_bound: " << it->first << endl;
      it = c.upper_bound(2);
      cout << "upper_bound: " << it->first << endl;
   }
   return 0;
}
