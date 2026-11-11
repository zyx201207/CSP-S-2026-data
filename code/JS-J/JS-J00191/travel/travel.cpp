#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve(){
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		string p1="",p2="";
		for(int i=0;i<2;i++){
			p1+=s1[i];
			p2+=s2[i];
		}
		if(p1==p2){
			cout<<1;
			if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='C'||s1[2]=='D')&&(s2[2]=='C'||s2[2]=='D'))){
				cout<<1;
				if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')) cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}
