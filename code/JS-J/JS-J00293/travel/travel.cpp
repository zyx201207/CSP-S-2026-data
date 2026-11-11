#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int is_same_chexiang=0;
	int is_same_pai=0;
	int is_same_ce=0;
	int is_near=0;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1==c2) {
		is_same_chexiang=1;
		string pai1 = ""+s1[0]+s1[1];
		string pai2 = ""+s2[0]+s2[1];
		if (pai1 == pai2) {
			is_same_pai=1;
			char ce1 = s1[2];
			char ce2 = s2[2];
			if (((ce1 >= 'A' && ce1 <= 'C') && (ce2 >= 'A' && ce2 <= 'C'))
			|| ((ce1 >= 'D' && ce1 <= 'F') && (ce2 >= 'D' && ce2 <= 'F'))) {
				is_same_ce = 1;
				if (abs(ce1-ce2) == 1) {
					is_near = 1;
				}
			}
		}
	}
	cout << is_same_chexiang << is_same_pai << is_same_ce << is_near;
	return 0;
	}
