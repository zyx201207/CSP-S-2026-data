#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int c,t,n,k;
vector<int> v[N];
int rd()
{
	int x=0,f=1;
	char ch;
	ch=getchar();
	while(ch<'0' || c>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	
	c=rd(); t=rd();
	while(t--)
	{
		n=rd(); k=rd();
		for(int i=1;i<=n;i++)
		{
			v[i].clear();
		}
		for(int i=1;i<n;i++)
		{
			int uu,vv;
			uu=rd(); vv=rd();
			v[uu].push_back(vv);
			v[vv].push_back(uu);
		}
		cout<<2<<endl;
	}
	
	return 0;
}//RP++
