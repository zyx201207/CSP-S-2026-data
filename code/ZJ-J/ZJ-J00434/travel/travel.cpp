#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	int f1=0,f2=0,f3=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1,f1=1;
	else cout<<0;
	if(s1[0]+s1[1]==s2[0]+s2[1]&&f1)cout<<1,f2=1;
	else cout<<0;
	if(f2&&(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'))cout<<1,f3=1;
	else cout<<0;
	if(f3&&(min(s1[2],s2[2])+1==max(s1[2],s2[2])||min(s1[2],s2[2])=='D'&&max(s1[2],s2[2])=='F'))cout<<1;
	else cout<<0;
	return 0;
}
