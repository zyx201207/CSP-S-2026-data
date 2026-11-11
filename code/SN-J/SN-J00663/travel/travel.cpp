//luoqiyuan xianshitieyizhongxue SN-J00663
#include<bits/stdc++.h>
#define int long long
using namespace std;
string c,s,cc,ss;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s[0]==ss[0]&&s[1]==ss[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((s[2]<='C'&&ss[2]<='C')||(s[2]>='D'&&ss[2]>='D')) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	int aa=s[2],bb=ss[2];
	if(abs(aa-bb)!=1) cout<<0;
	else cout<<1;
	return 0;
}
