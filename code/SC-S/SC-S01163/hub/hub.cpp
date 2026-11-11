#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k,head[1000010],idk,dp[1000010][2],maxd[1000010][2],mind[1000010][2];
struct node{int to,next;}e[2000010];
void adde(int u,int v){
	e[++idk]={v,head[u]};head[u]=idk;
}
void dfs(int u,int fa,int d){
	int cnt0=0,cnt1=0;
	for(int i = head[u];i;i=e[i].next){
		int v=e[i].to;if(v==fa)continue;
		dfs(v,u,d);
		dp[u][0]+=dp[v][0];dp[u][1]+=dp[v][1];
		cnt0+=(dp[v][0]>0);cnt1+=(dp[v][1]>0);
		maxd[u][0]=max(maxd[v][0]+1,maxd[u][0]);
		maxd[u][1]=max(maxd[v][1]+1,maxd[u][1]);
		mind[u][0]=min(mind[v][0]+1,mind[u][0]);
		mind[u][1]=min(mind[v][1]+1,mind[u][1]);
	}
	if(mind[u][0]==0x3f3f3f3f3f3f3f3f)mind[u][0]=mind[u][1]=0;
//	printf("%d:%d %d %d %d %d %lld\n",u,dp[u][0],dp[u][1],mind[u][0],mind[u][1],maxd[u][0],maxd[u][1]);
	if(cnt1==0){
		if(maxd[u][1]>2*d){
			dp[u][1]+=1;
			maxd[u][1]=mind[u][1]=0;
		}
	}else if(cnt1==1){
		if(maxd[u][1]>2*d){
			dp[u][1]+=1;
			maxd[u][1]=mind[u][1]=0;
		}
	}else{
		maxd[u][1]=mind[u][1]=0;int maxv=0; 
		for(int i = head[u];i;i=e[i].next){
			int v=e[i].to;if(v==fa)continue;
			dp[u][1]+=mind[v][1]+1;
			maxv=max(maxv,mind[v][1]);
		}
		dp[u][1]-=maxv;
	}
	if(cnt0==0){
		if(maxd[u][0]>2*d){
			dp[u][0]+=1; 
			maxd[u][0]=mind[u][0]=0;
		}
	}else if(cnt0==1){
		if(maxd[u][0]>2*d){
			if(dp[u][1]>dp[u][0]+1)
				dp[u][1]=dp[u][0]+1,mind[u][1]=maxd[u][1]=0;
			dp[u][0]+=(dp[u][0]!=0)*mind[u][0]+1;
			maxd[u][0]=mind[u][0]=0;
		}
	}else{
		maxd[u][1]=mind[u][1]=0;int maxv=0; 
		for(int i = head[u];i;i=e[i].next){
			int v=e[i].to;if(v==fa)continue;
			dp[u][0]+=mind[v][0]+1;
			maxv=max(maxv,mind[v][1]);
		}
		dp[u][0]++;
		if(dp[u][1]>dp[u][0]-maxv-1){
			dp[u][1]=dp[u][0]-maxv-1;
			maxd[u][1]=mind[u][1]=0;
		}
	} 
//	printf("%d:%d %d %d %d %d %lld\n",u,dp[u][0],dp[u][1],mind[u][0],mind[u][1],maxd[u][0],maxd[u][1]);
}
bool check(int d){
//	cout<<"check:"<<d<<"\n"; 
	for(int i = 1;i<=n;i++)dp[i][0]=dp[i][1]=0;
	for(int i = 1;i<=n;i++)maxd[i][0]=maxd[i][1]=d+1;
	for(int i = 1;i<=n;i++)mind[i][0]=mind[i][1]=0x3f3f3f3f3f3f3f3f;
	dfs(1,0,d);
	return min(dp[1][0],dp[1][1])<=k;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i = 1;i<=n;i++)head[i]=0;idk=0;
		for(int i = 1;i<n;i++){
			int u,v;cin>>u>>v;
			adde(u,v);adde(v,u);
		}
		int l=1,r=n;
		while(l<r){
			int mid=l+r>>1;
			if(check(mid))r=mid;
			else l=mid+1; 
		}
		cout<<l<<"\n";
	}
}