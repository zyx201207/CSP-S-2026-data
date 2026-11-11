#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a, b;
string sta, stb;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> sta >> b >> stb;
	if(a == b){
		cout << 1;
		string ia, ib;
		char ja, jb;
		ia += sta[0];
		ia += sta[1];
		ib += stb[0];
		ib += stb[1];
		ja = sta[2];
		jb = stb[2];
		if(ia == ib){
			cout << 1;
			if(ja <= 'C' && jb <= 'C' || ja >= 'D' && jb >= 'D'){
				cout << 1;
				if(abs(int(ja - jb)) == 1) cout << 1 << endl;
				else cout << 0 << endl;
			}
			else cout << "00" << endl;
		}
		else cout << "000" << endl;
	}
	else cout << "0000" << endl;
	return 0;
}

