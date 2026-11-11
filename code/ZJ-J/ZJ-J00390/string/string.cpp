#include<bits/stdc++.h>
#define int long long
const int N=2e5+10;
using namespace std;
map<int,char> mp;
int n;
int L[N];
int R[N];
char op[N];
int now=1;
int ans;
int sum;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)	
	{
		int x;
		cin>>x>>op[i];
		L[i]=now;
		R[i]=now+x-1;
		now+=x;
		sum+=x;
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<L[i]<<" "<<R[i]<<" "<<op[i]<<'\n';
//	}
	now=1;
	while(now<=sum/2)
	{
		int i=lower_bound(R+1,R+n+1,now)-R;
		int x;
		x=sum-now+1;
		int it1=lower_bound(R+1,R+n+1,x)-R;
		int w=min(R[it1]-L[it1]+1,R[i]-L[i]+1);
//		cout<<i<<" "<<x<<" "<<it1<<" *"<<op[it1]<<" *"<<op[i]<<" ";
		if(op[it1]!=op[i])
		{
			ans+=w;
		}
		now+=w;	
		
//		cout<<ans<<" "<<now<<'\n';
	}
	cout<<ans;
	return 0;
}