#include "test_map.hpp"

typedef map<int, int> Map;
typedef pair<int, int> Pair;

Map basic()
{
	Map m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(4, 4));
	m.insert(make_pair(5, 5));
	m.insert(make_pair(6, 6));
	return m;
}

int test() {
	Map c = ::basic();

    std::cout << "----------> at <----------" << std::endl;
    try {
        c[0] = c.at(1);
        c.at(2) = c[3];
        c.at(2) = c.at(0);
        c.at(101);
        c[102];
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    print_map<Map>(c);

	std::cout << "----------> insert <----------" << std::endl;
    pair<Map::iterator, bool> r;
    print_map<Map>(c);
    r = c.insert(Pair(10000, 10000));
    c[-1] = r.first->second;
    c[-2] = r.second;
    print_map<Map>(c);
    r = c.insert(Pair(-1, -1));
    c[-3] = r.first->second;
    c[-4] = r.second;
    print_map<Map>(c);

	std::cout << "----------> erase <----------" << std::endl;
//    c.erase(1);
//    c.erase(2);
//    print_map<Map>(c);
//    c[5] = c.erase(0);
//    print_map<Map>(c);
//    c[0] = 1000;
//    c[2] = 999999;
//    c[4] = c.erase(10000);
//    c[3] = c.erase(2);
//    print_map<Map>(c);


	std::cout << "----------> swap <----------" << std::endl;


	std::cout << "----------> clear <----------" << std::endl;
	print_map<Map>(c);
   c.clear();
	print_map<Map>(c);
   c[10] = 9;
	print_map<Map>(c);
   c.clear();
	print_map<Map>(c);
   c[2] = 42;
	print_map<Map>(c);
   c[50] = 20;
	print_map<Map>(c);

	return 0;
}
