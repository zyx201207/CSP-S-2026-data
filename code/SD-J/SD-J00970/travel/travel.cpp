#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
//#define int long long
using namespace std;
const int N = 100005;
int n, m;
string c1, c2, c3, c4;
struct node{
	int x, y;
};
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
	cin >> c1 >> c2 >> c3 >> c4;
	if(c1 == c3){
		cout << 1;
		string t1 = "" + c2[0] + c2[1];
		string t2 = "" + c4[0] + c4[1];
		if(t1 == t2){
			cout << 1;
			if((c2[2] == 'A' || c2[2] == 'B' || c2[2] == 'C') && (c4[2] == 'A' || c4[2] == 'B' || c4[2] == 'C')){
				cout << 1;
				int t1 = c2[2] - 'A';
				int t2 = c4[2] - 'A';
				if(abs(t1 - t2) == 1){
					cout << 1;
				}else{
					cout << 0;
				}
			}else if((c2[2] == 'D' || c2[2] == 'F') && (c4[2] == 'D' || c4[2] == 'F')){
				cout << 11;
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}



