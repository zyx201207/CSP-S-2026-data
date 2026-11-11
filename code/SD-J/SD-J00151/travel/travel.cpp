#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
const int N=1e5+5,MAX=1e18,MIN=-1e18;
string c1,s1,c2,s2;
void solve(){
	bool flag=1;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return;
	}
	
	if(s1[0]+s1[1]==s2[0]+s2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return;
	}
	
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
		cout<<1;
	}else{
		if((s1[2]=='D'||s1[2]=='E')&&(s2[2]=='D'||s2[2]=='E')){
			cout<<1;
		}else{
			cout<<"00";
			return;
		}
	}
	
	if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='C'&&s2[2]=='D')){
		cout<<0;
		return;
	}
	if((s1[2]+1==s2[2]||s1[2]-1==s2[2])&&flag==1){
		cout<<1;
	}else{
		cout<<0;
		return;
	}
}
signed main(){
	IOS
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1;//cin>>T;
	while(T--) solve();
	return 0;
}
//T1
