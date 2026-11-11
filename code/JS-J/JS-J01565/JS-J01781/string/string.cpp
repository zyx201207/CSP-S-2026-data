#include <iostream>
#include <utility>
#include <list>
using namespace std;
#define fir first
#define sec second
#define elif else if
typedef long long ll;

const int N(2e5+5);
int n;
pair<ll, char> x;
list<pair<ll, char> > s;
ll ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> x.fir >> x.sec;
		if (!s.empty() && x.sec==s.back().sec) {
			s.back().fir += x.fir;
		}
		else {
			s.push_back(x);
		}
	}
	list<pair<ll, char> >::iterator i=s.begin(), j=s.end();
	j--;
	while (i != j) {
		if (i->sec != j->sec) {
			if (i->fir == j->fir) {
				ans += i->fir;
				i++;
				s.pop_front();
				if (i == j) break;
				j--;
				s.pop_back();
			}
			elif (i->fir > j->fir) {
				ans += j->fir;
				i->fir -= j->fir;
				j--;
				s.pop_back();
			}
			else {
				ans += i->fir;
				j->fir -= i->fir;
				i++;
				s.pop_front();
			}
		}
		else {
			if (i->fir == j->fir) {
				i++;
				s.pop_front();
				if (i == j) break;
				j--;
				s.pop_back();
			}
			elif (i->fir > j->fir) {
				i->fir -= j->fir;
				j--;
				s.pop_back();
			}
			else {
				j->fir -= i->fir;
				i++;
				s.pop_front();
			}
		}
	}
	cout << ans;
	return 0;
}
