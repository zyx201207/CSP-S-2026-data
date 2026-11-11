#include<bits/stdc++.h>
#define int long long
using namespace std;
int ra,rb,flag;
string sa,sb;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ra>>sa>>rb>>sb;
	if(ra==rb)cout<<"1",flag=1;
	else cout<<"0";
	if(flag&&sa[0]*10+sa[1]==sb[0]*10+sb[1])flag=1,cout<<"1";
	else flag=0,cout<<"0";
	if(flag&&(sa[2]<='C'&&sb[2]<='C'||sa[2]>='D'&&sb[2]>='D'))flag=1,cout<<"1";
	else flag=0,cout<<"0";
	if(flag&&(sa[2]==sb[2]+1||sa[2]==sb[2]-1))cout<<"1";
	else cout<<"0";
	return 0;
}
