#include<bits/stdc++.h>
//#define int long long
using namespace std;
string s1,c1,s2,c2;
bool f1,f2,f3;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s1>>c1>>s2>>c2;
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<0;
		f1=0;
	}else{
		cout<<1;
		f1=1;
	}
	if(f1&&c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<1;
		f2=1;
	}else{
		cout<<0;
		f2=0;
	}
	if(f2){
		int x,y;
		if(c1[2]=='A'||c1[2]=='B'||c1[2]=='C') x=1;
		else x=2;
		if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C') y=1;
		else y=2;
		if(x==y){
			cout<<1;
			f3=1;
		}else{
			cout<<0;
			f3=0;
		}
	}else{
		cout<<0;
		f3=0;
	}
	if(f3&&abs(c1[2]-c2[2])==1) cout<<1;
	else cout<<0;
	return 0;
}