#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else {cout<<"0000";return 0;}
	if(b[0]==d[0]&&b[1]==d[1]) cout<<1;
	else {cout<<"000";return 0;}
	if(((b[2]-'A'+1)<='C'&&(d[2]-'A'+1)<='C')||((b[2]-'A'+1)>='D'&&(d[2]-'A'+1)>='D')) cout<<1;
	else {cout<<"00";return 0;}
	if(((b[2]-'A'+1)-(d[2]-'A'+1))==1||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')||((b[2]-'A'+1)-(d[2]-'A'+1))==-1) cout<<1;
	else cout<<0;
	return 0;
}
//省二没问题了，T2想出正解+dfs会的话能省一
//这波亏了
//这个也有神人榜吗，我也要上，洛谷关注KE_J谢谢喵 
