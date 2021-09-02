#include <iostream>
#include <functional>
#include <string>

struct S {
	std::string first_name;
	std::string last_name;
};

namespace std {
	template<>
	class hash<S> {
	public:
		size_t operator()(const S& s) const
		{
			size_t h1 = std::hash<std::string>()(s.first_name);
			size_t h2 = std::hash<std::string>()(s.last_name);//hash原理有空看
			return h1 ^ (h2 << 1);
		}
	};
}

int main()
{
	S s;
	s.first_name = "Bender";
	s.last_name = "Rodriguez";
	std::hash<S> hash_fn;

	std::cout << "hash(s) = " << hash_fn(s) << "\n";
	return 0;
}
