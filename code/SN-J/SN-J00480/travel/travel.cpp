//Kill t1 only used 6 mins!!!
//MingDynasty -> https://www.mgdyqwq.com
#include<bits/stdc++.h>
using namespace std;
int a,b,n;
string c1,s1,c2,s2;
bool flag;
bool check(string q,string w){
	if(q[2]=='A') return w[2]=='B'&&flag;
	if(q[2]=='B') return (w[2]=='A'||w[2]=='C')&&flag;
	if(q[3]=='C') return w[2]=='B'&&flag;
	if(q[4]=='D') return w[2]=='F'&&flag;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c1>>s1>>c2>>s2;
	map<char,bool> f;
	f['A']=f['B']=f['C']=1;
	f['D']=f['F']=0;
	if(c1==c2) cout<<"1";
	else cout<<"0000",exit(0);
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<"1",flag=1;
	else cout<<"0";
	if(f[s1[2]]==f[s2[2]]&&flag) cout<<1;
	else cout<<0;
	if(check(s1,s2)) cout<<1;
	else cout<<0;
	return 0;
}
