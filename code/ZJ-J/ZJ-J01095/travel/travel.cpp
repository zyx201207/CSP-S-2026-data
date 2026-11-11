#include <bits/stdc++.h>
#define int long long
using namespace std;
int i,che1,che2,pai1,pai2,zm1,zm2;
char s1[5],s2[5],c1[5],c2[5];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s1+1>>c1+1>>s2+1>>c2+1;
	for(i=1;i<=2;i++)
		che1=che1*10+(s1[i]-'0'),che2=che2*10+(s2[i]-'0');
	if(che1!=che2){
		cout<<"0000";return 0;
	}
	cout<<1;
	for(i=1;i<=2;i++)
		pai1=pai1*10+(c1[i]-'0'),pai2=pai2*10+(c2[i]-'0');
	if(pai1!=pai2){
		cout<<"000";return 0;
	}
	cout<<1;
	zm1=c1[3]-65;
	zm2=c2[3]-65;
	if((zm1>=3&&zm2<=2)||(zm1<=2&&zm2>=3)){
		cout<<"00";return 0;
	}
	cout<<1;
	if(zm1>=3&&zm2>=3){
		cout<<1;return 0;
	}
	if((zm1==0&&zm2==2)||(zm1==2&&zm2==0)) cout<<0;
	else cout<<1;
	return 0;
}
