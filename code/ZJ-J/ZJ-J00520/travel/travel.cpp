#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
const int N=1e5+5;
string c1,s1,c2,s2;

void solve(){
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return ;
	}
	else cout<<"1";
	if(s1.substr(0,2)!=s2.substr(0,2)){
		cout<<"000";
		return ;
	}
	else cout<<"1";
	int a=(int)(s1[2]-'A'),b=(int)(s2[2]-'A');
	//0 1 2 3 4
	if(a<3&&b<3||a>=3&&b>=3){
		cout<<"1";
	}
	else{
		cout<<"00";
		return ;
	}
	if(abs(a-b)==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
} 

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	system("fc travel.out travel5.ans");
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}
/*
100pts
*/ 
