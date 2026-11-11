#include<bits/stdc++.h>
using namespace std;
#define int long long
int c1,c2,fl1,fl2,fl3,fl4;
string s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	fl1=(c1==c2?1:0);
	fl2=(fl1&&s1[0]==s2[0]&&s1[1]==s2[1]?1:0);
	fl3=(fl2&&(s1[2]>='D'&&s2[2]>='D'||s1[2]<='C'&&s2[2]<='C')?1:0);
	fl4=(fl3&&abs(s1[2]-s2[2])==1?1:0);
	cout<<fl1<<fl2<<fl3<<fl4;
}