#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1,c2;
string s1="",s2="";
bool f1,f2,f3,f4;
map<char,int>mp,t;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c1,cin>>s1,cin>>c2,cin>>s2;
	mp['A']=mp['B']=mp['C']=1;
	mp['D']=mp['E']=0;
	t['A']=1,t['B']=2,t['C']=3,t['D']=4,t['E']=5;
	if(c1==c2)f1=true;
	if(f1&&s1[0]==s2[0]&&s1[1]==s2[1])f2=true;
	if(f2&&mp[s1[2]]==mp[s2[2]])f3=true;
	if(f3&&(t[s1[2]]-t[s2[2]]==1||t[s1[2]]-t[s2[2]]==-1))f4=true;
	cout<<f1<<f2<<f3<<f4;
	return 0;
}