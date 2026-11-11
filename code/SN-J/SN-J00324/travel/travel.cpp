#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e5+5,inf=1e18;
bool w[1000];
bool check(char a,char b)
{
	if(a>b) swap(a,b);
	if(a=='A'&&b=='B') return 1;
	if(a=='B'&&b=='C') return 1;
	if(a=='D'&&b=='F') return 1;
	return 0;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	w['A']=w['B']=w['C']=1;
	w['D']=w['F']=0;
	
	string s1,s2,t1,t2;
	cin>>s1>>s2>>t1>>t2;
	if(s1==t1) 
	{
		cout<<1;
		if(s2[0]==t2[0]&&s2[1]==t2[1]) 
		{
			cout<<1;
			char a=s2[2],b=t2[2];
			cout<<(w[signed(a)]==w[signed(b)]);
			cout<<check(a,b);
		}
		else cout<<"000";
	}	
	else cout<<"0000";
	return 0;	
}















//fjy I love you!
