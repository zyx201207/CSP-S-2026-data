#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
const double eps=1e-6;
string s1,s2,c1,c2;
void solve(){
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')){
				cout<<1;
				if(abs(s1[2]-s2[2])==1)cout<<1;
				else cout<<0;
			}
			else cout<<"00";	
		}
		else cout<<"000";	
	}
	else cout<<"0000";
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;	
}
/*
JYPO HAVE 1e18 npies
JYPO IS YAG
I wont lose!!!
Y   Y    A       GGGGG
 Y Y    A A     G
  Y    AAAAA    G    GG
  Y   A     A   G     G
  Y  A       A   GGGGG
  Y 
*/ 
