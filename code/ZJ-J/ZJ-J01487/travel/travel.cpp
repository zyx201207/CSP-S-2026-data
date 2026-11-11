#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,c2,s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
	else cout<<0;
	int p1=s1[2]-'A';
	int p2=s2[2]-'A';
	if(p1>p2)swap(p1,p2);
	if(c1==c2&&p1>=3&&s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
	else if(c1==c2&&p2<3&&s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
	else cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&((p1==3&&p2==4)||(p1==0&&p2==1)||(p1==1&&p2==2)))cout<<1;
	else cout<<0;
}
