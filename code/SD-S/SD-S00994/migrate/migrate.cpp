#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef const int cint;
cint N=2e6+10;
ll n,m,t,c; 
ll a[N],sq[N],sh[N];
queue<ll> q; 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		
		for(int i=1;i<=n;i++)
		{
			while(q.size()&&a[i]-a[q.front()]>m){
				q.pop();
			}
			if(!q.size())sq[i]=1;
			else if(a[q.front()+1]-a[q.front()-1]<=m)
			{
				sq[i]=q.size()+1;
			}
			else sq[i]=sq[i-1]+1;
//			cout<<sq[i]<<" ";
			q.push(i);
		}
//		cout<<endl;
		while(q.size())q.pop();
		for(int i=n;i>=1;i--)
		{
			while(q.size()&&-a[i]+a[q.front()]>m){
				q.pop();
			}
			if(!q.size())sh[i]=1;
			else if(a[q.front()+1]-a[q.front()-1]<=m)
			{
				sh[i]=q.size()+1;
			}
			else sh[i]=sh[i+1]+1;
//			cout<<sh[i]<<" ";
			q.push(i);
		}
		while(q.size())q.pop();
		ll ans=0;
		for(int i=1;i<=n-3;i++)
		{
			if((a[i+3]-a[i]>m)&&(a[i+2]-a[i]<=m&&a[i+3]-a[i+2]<=m)&&(a[i+1]-a[i]<=m&&a[i+3]-a[i+1]<=m))
			{
				ans+=sq[i]*sh[i+3];
			}
		}
		cout<<ans<<"\n";
	}
		


	return 0;
}



