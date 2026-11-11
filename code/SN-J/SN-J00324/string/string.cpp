#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+5,inf=1e18;
int n;
int sum=0;
vector<pair<int,char> > V,g;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k;
		char c;
		cin>>k>>c;
		V.push_back({k,c});
		sum+=k; 
	}
	int cnt=0;
	bool flag=0;
	for(int i=0;i<n;i++)
	{
		int k=V[i].first;
		char c=V[i].second;
		cnt+=k;
		if(cnt>=(sum+1)/2&&(cnt-k)<(sum+1)/2)
		{
//			if(sum&1)
//			{
//				g.push
//			}
			g.push_back({(sum+1)/2-(cnt-k),c});
			g.push_back({cnt-(sum+1)/2,c});
		}
		else g.push_back({k,c});
	}
//	for(auto kk:g) cout<<kk.first<<" "<<kk.second<<endl;
	int sum1=0,sum2=0,l=0,r=g.size()-1,ans=0;
	sum1=g[l].first,sum2=g[r].first;
	while(1)
	{
		if((sum1>sum/2&&sum2>sum/2)||l>r) break;
		int	k1=g[l].first,k2=g[r].first;
		char c1=g[l].second,c2=g[r].second;
		if(k1<k2) 
		{
	//		cout<<1<<endl; 
			g[r].first-=k1;
			l++;
			sum1+=g[l].first;
			ans+=(c1!=c2)*k1; 
		}
		else if(k1>k2)
		{
	//		cout<<c1<<" "<<c2<<" "<<k2<<endl;
			g[l].first-=k2;
			r--;
			sum2+=g[r].first;
			ans+=(c1!=c2)*k2;
		}
		else 
		{
	//		cout<<3<<endl;
			l++;
			r--;
			sum1+=g[l].first;
			sum2+=g[r].first;
			ans+=(c1!=c2)*k1;
		}
	//	cout<<sum1<<" "<<sum2<<" "<<l<<" "<<r<<endl; 
	}
	cout<<ans;
	return 0;	
}















//fjy I love you!
