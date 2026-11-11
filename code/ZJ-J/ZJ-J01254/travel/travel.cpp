#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
string x,y,q,p;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>x>>y>>q>>p;
	if(x==q){
		cout<<1;
		if(y[0]==p[0] and y[1]==p[1]){
			cout<<1;
			if('A'<=y[2] and y[2]<='C' and 'A'<=p[2] and p[2]<='C'){
				cout<<1;
				if(abs(y[2]-p[2])==1) cout<<1;
				else cout<<0;
			}
			else if('D'<=y[2] and y[2]<='F' and 'D'<=p[2] and p[2]<='F') cout<<"11";
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
