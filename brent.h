#include <vector>

using std::vector;


class entry {
	public:
		bool valid;
		int data;

		entry() {
			valid = false;
		}
};
class Brent {
public:
	vector<entry> data_vec;

public:
	Brent(int);
    int hash(int);
    int hash2(int);
	void insert(int);
	vector<int> calculateLQ(int, int);
	int find_num_probes(int) const;
	double find_average_num_probes() const;

};