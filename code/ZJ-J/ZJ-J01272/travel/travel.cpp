#include<bits/stdc++.h>
#define int long long
using namespace std;
string a[10];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[1]>>a[2]>>a[3]>>a[4];
	if(a[1]==a[3]){
		if(a[2][0]==a[4][0]&&a[2][1]==a[4][1]){
			if(a[2][2]>='A'&&a[2][2]<='C'&&a[4][2]>='A'&&a[4][2]<='C'){
				if(a[2][2]=='B'||a[4][2]=='B') cout<<"1111";
				else cout<<"1110";
			}
			else if(a[2][2]=='D'&&a[4][2]=='F'||a[2][2]=='F'&&a[4][2]=='D') cout<<"1111";
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
