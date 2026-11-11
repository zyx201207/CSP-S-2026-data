#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	string a,b,c,d;
	cin>>a>>c>>b>>d;
	if(a==b)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(c[0]+c[1]==d[0]+d[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(((c[2]=='D'||c[2]=='F')&&(d[2]>='A'&&d[2]<='C'))||((d[2]=='D'||d[2]=='F')&&(c[2]>='A'&&c[2]<='C'))){
		cout<<"00";
		return 0;
	}
	else cout<<1;
	if(abs(int(c[2]-d[2]))==1)cout<<1;
	else cout<<0;
	return 0;
}


