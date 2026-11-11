#include<bits/stdc++.h>
using namespace std;
const int N=5e5+12;
typedef long long ll;
ll c,T,n,d,a[N],dp[N],dp2[N];
struct Bit
{
	int tree[N]={0};
	int lowbit(int x){
		return (x&-x);
	}
	void add(int x,int k)
	{
		for(;x<=n;x+=lowbit(x))tree[x]+=k;
	}
	int ask(int x)
	{
		int sum=0;
		for(;x;x-=lowbit(x))sum+=tree[x];
		return sum; 
	}
}tr;
pair<int,int> dk[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int anss=0;
		for(int i=1;i<=n;i++)
		{
			memset(dk,0,sizeof dk);
			memset(dp,0,sizeof dp);
			memset(dp2,0,sizeof dp2);
			memset(tr.tree,0,sizeof tr.tree);
			tr.add(i,1);dp[i]=0;
			dk[0]=make_pair(i,i);
			for(int j=i+1;j<=n;j++)
			{
				int l=i,r=j-1,ans=0;
				while(l<=r)
				{
					int mid=l+r>>1;
					if(abs(a[j]-a[mid])<=d)ans=mid,r=mid-1;
					else l=mid+1;
				}
				if(ans==0)continue;
				dp[j]=dp[ans]+1;
				dp2[j]=tr.ask(dk[dp[ans]].second)-tr.ask(ans-1);
				if(dp[j]!=dp[j-1])dk[dp[j]]=make_pair(j,j);
				else dk[dp[j]]=make_pair(dk[dp[j]].first,j);
				tr.add(j,dp2[j]);
//				cout<<i<<" "<<j<<" "<<dp[j]<<" "<<dp2[j]<<" "<<ans<<" "<<(dp2[j]==2)<<"\n";
				if(dp2[j]==2)anss++;
			}
		}
		cout<<anss<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
