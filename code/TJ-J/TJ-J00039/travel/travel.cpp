#include<bits/stdc++.h>
using namespace std;
int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	if(a==c){
		flag1 = 1;
		if(b[0]==d[0]&&b[1]==d[1]){
			flag2 = 1;
			if((((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F')))&&b[2]!=d[2]){
				flag3 = 1;
				if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='D'&&d[2]=='F')||(b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B')||(b[2]=='F'&&d[2]=='D')) flag4 = 1;
			}
		}
	}
	cout << flag1 << flag2 << flag3 << flag4 << "\n";
	return 0;
}
