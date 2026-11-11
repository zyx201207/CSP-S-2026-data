#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c,d;
char x,y;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>c>>d>>y;
	if(a!=c) cout<<"0000";
	else{
		if(b!=d) cout<<"1000";
		else{
			if(min(x,y)>='D'||max(x,y)<='C'){
				if(abs(x-y)==1) cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
	}
	return 0;
}
