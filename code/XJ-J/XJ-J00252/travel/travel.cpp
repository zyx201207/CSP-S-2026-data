#include<bits/stdc++.h>
using namespace std;
char RC[10], RS[10], XC[10], XS[10];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> RC >> RS >> XC >> XS;
	if(RC[0] == XC[0] && RC[1] == XC[1]){
		cout << 1;
		if(RS[0] == XS[0] && RS[1] == XS[1]){
			cout << 1;
			int r = (RS[2] <= 'C' ? 0 : 1);
			int x = (XS[2] <= 'C' ? 0 : 1);
			if(r == x){
				cout << 1;
				//cout << (char)(RS[2] + 1);
				if(RS[2] + 1 == XS[2] || RS[2] - 1 == XS[2])
					cout << 1;
				else 
					cout << 0;
			}else
				cout << 0 << 0;
		}else
			cout << 0 << 0 << 0;
	}else
		cout << 0 << 0 << 0 << 0;
	return 0;
}
