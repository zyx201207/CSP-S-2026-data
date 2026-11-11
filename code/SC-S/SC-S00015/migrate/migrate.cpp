#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
const ll INF=2e18+5;
int c,T,n;
ll d,cnt;
ll a[N],ans[N][N];
map<pair<int,int>,ll> mp,cl;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		cnt=0;
		mp=cl;
		memset(a,0,sizeof a);
		memset(ans,0,sizeof ans);
		for(int i=1;i<=n;++i)	cin>>a[i];
		for(int i=2;i<=n;++i)
			for(int j=1;j<i;++j)
			{
				if(a[i]-a[j]>d)	mp[{j,i}]=INF;
				else mp[{j,i}]=a[i]-a[j],ans[j][i]++;
			}
//		ans[1][1]=1;
		for(int i=1;i<n;++i)
			for(int j=i+1;j<=n;++j)
				for(int k=i;k<j;++k)
					if(mp[{i,j}]==INF&&mp[{k,j}]!=INF)
						ans[i][j]=ans[i][k]+ans[k][j];
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(ans[i][j]==2)	cnt++;
		cout<<cnt<<"\n";		
	}
	return 0;
}