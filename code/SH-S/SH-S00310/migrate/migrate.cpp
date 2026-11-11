#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c,d,t,le[500010],dis[510],x[100010],cnt[100010],dp[100010],sum=0,ans=0;
vector<int>vec[500010];
void dfs(int u){
	for(auto v:vec[u]){
		if(dis[v]==dis[u]+1)cnt[v]+=cnt[u],dfs(v);
		if(dis[v]>dis[u]+1)dis[v]=dis[u]+1,cnt[v]=1,dfs(v);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(x,0,sizeof(x));
		memset(cnt,0,sizeof(le));
		memset(dis,0x3f,sizeof(dis));
		cin>>n>>d;
		for(int i=1;i<=n;i++)vec[i].clear();
//		int la=0,cnt=0,sum=0,ll=0,cntdp;
//		dp[1]=1;
//		for(int i=1;i<=n;i++){
//			cin>>x[i];
//			int l=1,r=i,ans=i;
//			while(l<=r){
//				int mid=(l+r)/2;
//				if(x[i]-x[mid]<=d)ans=mid,r=mid-1;
//				else l=mid+1;
//			}
//			le[i]=ans;
//			while(la<=ans)cnt-=le[la],la++;
////			dp[i]=dp[le[i]]+i-le[i];
////			cntdp+=dp[le[le[i-1]]];
////			while(ll<=ans)cntdp-=dp[le[le[ll]]],ll++;
//			sum+=((le[i]*(i-le[i]-1)-cnt)==1);//*way[le[le[le[i+1]]]];
//			cout<<(le[i]*(i-le[i]-1)-cnt)<<" ";
//			cnt+=le[i];
//		}
//		cout<<sum<<endl;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			for(int j=i-1;j>=1;j--){
				if(x[i]-x[j]<=d)vec[j].push_back(i);
			}
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			memset(dis,0x3f,sizeof(dis));
			dis[j]=0;
			dfs(j);
			for(int i=j;i<=n;i++){
				if(cnt[i]==2){
					ans++;
				}
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
/*
d=3
1 2 3 4 6
d=4
1 3 4 5 7
1-4-6
1-3-6
xyzw
z-x<=d
w-y<=d
w-(y-a)>d
y=le[w]
xz=sum(le[w]+1,w):le[w]-le[i]
10 3
0 3 6 7 8 9 10 11 14 17

*/
