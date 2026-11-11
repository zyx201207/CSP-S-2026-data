//袁浩文 西安辅轮中学 SN-J00625 
#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define elif else if
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(x) (x&-x)
#define setdigit(x) cout<<fixed<<precision(x)
#define debug(...) fprintf(stderr,##__VA_ARGS__)
using namespace std;
string s1,s2,s3,s4;
void solve(){
	cin>>s1>>s2>>s3>>s4;
	int f1=0,f2=0,f3=0;
	if(s1==s3)cout<<1,f1=1;
	else cout<<0;
	if(f1&&(s2[0]==s4[0])&&(s2[1]==s4[1]))cout<<1,f2=1;
	else cout<<0;
	if(f2&&(s2[0]==s4[0])&&(s2[1]==s4[1])&&((s2[2]<='C'&&s4[2]<='C')||(s2[2]>='D'&&s4[2]>='D')))cout<<1,f3=1;
	else cout<<0;
	if(f3&&(s2[0]==s4[0])&&(s2[1]==s4[1])&&((s2[2]=='A'&&s4[2]=='B')||(s2[2]=='B'&&s4[2]=='A')||(s2[2]=='B'&&s4[2]=='C')||(s2[2]=='C'&&s4[2]=='B')||(s2[2]=='D'&&s4[2]=='F')||(s2[2]=='F'&&s4[2]=='D')))cout<<1;
	else cout<<0;
}
signed main(){
	string filename="travel";
	freopen((filename+".in").c_str(),"r",stdin),freopen((filename+".out").c_str(),"w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int Case=1;
//	cin>>Case;
	while(Case--)solve();
}
//8:47
