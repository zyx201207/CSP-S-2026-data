#include<bits/stdc++.h>
#define fri freopen("travel.in","r",stdin)
#define fro freopen("travel.out","w",stdout)
#define con const int
#define endl '\n'
#define intl long long
using namespace std;
void solve(){
	string a,b,c,d,ans="";
	cin>>a>>b>>c>>d;
	a=" "+a;
	b=" "+b;
	c=" "+c;
	d=" "+d;
	if(a==c){
		ans+="1";
	}
	else{
		ans+="0000";
		cout<<ans;
		return;
	}
	if(b[1]==d[1]&&b[2]==d[2]){
		ans+="1";
	}
	else{
		ans+="000";
		cout<<ans;
		return ;
	}
	if((b[3]<='C'&&d[3]<='C')||(b[3]>='D'&&d[3]>='D')){
		ans+="1";
	}
	else{
		ans+="00";
		cout<<ans;
		return ;
	}
	if(abs(b[3]-d[3])<=1){
		ans+="1";
	}
	else{
		ans+="0";
	}
	cout<<ans;
}
int main(){
	fri;fro;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}

