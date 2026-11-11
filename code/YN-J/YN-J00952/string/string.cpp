// f?ck

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

size_t n;

size_t all_n;

vector<size_t> a;
vector<char> c;
vector<size_t> quque_free;

vector<int> try_count;

bool cmp(size_t a, size_t b) {
	return a > b;
}

bool is_repeat_str() {
	for (size_t i = 0; i < n / 2; i++) {
		if (!(a[i] == a[n - 1 - i] && c[i] == c[n - 1 - i])) {
			return false;	
		}
	}
	return true;
}

void try_1();
void try_2();
void try_3();

int main(){
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	a.resize(n);
	c.resize(n);
	bool flag = false;
	for (size_t i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
		
		if (!flag) {
			flag = true;
			continue;
		}
		
		// mix up some same char groups
		if (c[i - 1] == c[i]) {
			a[i - 1] += a[i];
			n -= 1;
			i -= 1;
		}
		
	}
	a.resize(n);
	c.resize(n);
	
	if (n == 1) {
		cout << 0;
		return 0;
	}
	
	// free some repeat data
	for (size_t i = 0; i < n / 2; i++) {
		if (a[i] == a[n - 1 - i] && c[i] == c[n - 1 - i]) {
			quque_free.push_back(i);
			quque_free.push_back(n - i);
		}
	}
	sort(quque_free.begin(), quque_free.end(), cmp);
	for (const size_t i : quque_free) {
		a.erase(a.begin() + i, a.begin() + i + 1);
		c.erase(c.begin() + i, c.begin() + i + 1);
	}
	
	if (a.size() < 2) {
		cout << 0;
		return 0;
	} else if (a.size() == 2) {
		cout << min(a[0], a[1]);
		return 0;
	}
	
	n = a.size();
	
	for (const size_t i : a) {
		all_n += i;
	}
	
	try_count.resize(3);
	try_1();
	try_2();
	try_3();
	sort(try_count.begin(), try_count.end());
	cout << try_count[0];
	
	return 0;
}

// find count max chars, insert other char
void try_1() {
	
	size_t tc = 0;
	
	unordered_map<char, size_t> _count;
	unordered_set<char> _char_set;
	
	char _max_char;
	size_t _max_count = 0;
	
	_count.clear();
	_char_set.clear();
	for (size_t i = 0; i < n; i++) {
		_char_set.emplace(c[i]);
		_count[c[i]] += a[i];
	}
	for (const char i : _char_set) {
		if (_count[i] > _max_count){
			_max_count = _count[i];
			_max_char = i;
		}
	}
	
	for (size_t i = 0; i < n / 2; i++) {
		bool _l = c[i] != _max_char;
		bool _r = c[n - 1 - i] != _max_char;
		if (_l && _r)
			tc += min(a[i], a[n - 1 - i]);
		else 
			if (_l)
				tc += a[i];
			if (_r)
				tc += a[n - 1 - i];
	}
	
	try_count[0] = tc;
	return;
}

void try_2(){
	try_count[1] = all_n / 2;
	return;
}
void try_3() {
	try_count[2] = all_n;
	return;
}
