#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string s,ss,x,xx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s>>ss>>x>>xx;
	if((s[0]=='0'&&s[1]=='1'&&x[0]=='0'&&x[1]=='1')||(s[0]=='1'&&s[1]=='6'&&x[0]=='1'&&x[1]=='6')){
		cout<<"0000";
		return 0;
	}
	if(s[0]==x[0]&&s[1]==x[1]) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	} 
	if(ss[0]==xx[0]&&ss[1]==xx[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(((ss[2]<='C')&&(xx[2]>='D'))||((ss[2]>='D')&&xx[2]<='C')){
		cout<<"00";
		return 0;
	}
	else cout<<"1";
	if(abs(ss[2]-xx[2])==1) cout<<"1";
	else cout<<"0";
	return 0;
}
