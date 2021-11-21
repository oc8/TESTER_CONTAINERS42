#include "test_vector.hpp"

int test() {
	vector<NoLeaksPlease> v;
	vector<NoLeaksPlease> v_empty;
	v.push_back(NoLeaksPlease(2, "test1"));
	v.push_back(NoLeaksPlease(2, "test2"));
	v.push_back(NoLeaksPlease(2, "test3"));
	v.push_back(NoLeaksPlease(2, "test4"));
	v.push_back(NoLeaksPlease(2, "test5"));
	const vector<NoLeaksPlease> vc(v);
	print_vec<vector<NoLeaksPlease> >(v);
	print_vec<vector<NoLeaksPlease> >(vc);

	std::cout << "----------> get_allocator <----------" << std::endl;
	vector<NoLeaksPlease>::allocator_type alloc = v.get_allocator();
	std::cout << typeid(alloc).name() << std::endl;

	return 0;
}