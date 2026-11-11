#include<bits/stdc++.h>
#define LANH using
#define AK namespace
#define CSPS std
LANH AK CSPS;
int n,k;
struct node{
	vector<int>s;
}a[1000009];
void dfs(int x,int fa){
	for(int i:a[x].s){
		if(i==fa)continue;
		dfs(i,x);
	}
}
int c;
bool vis[1009];
bool sd[100009];
int dis[1009],dis2[1009];
void Main(){
//	if(n<=100){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				for(int k=1;k<=n;k++){
//					dp[i][j][k]=109; 
//				} 
//			}
//		}
//	} 
	memset(sd,0,sizeof sd);
	for(int i=1;i<=n;i++)a[i].s.clear();
	cin>>n>>k;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		a[x].s.push_back(y);
		a[y].s.push_back(x);
	}
	if(c==13||c==14){
		if(2*k<=n){
			cout<<ceil(1.0*(n/2-k)/4.0)+1<<'\n';
		}else if(k<n){
			cout<<1<<"\n";
		}else puts("0");
		return ;
	}
	queue<int>q;
	while(!q.empty())q.pop();
	dfs(1,0);
	if(n<=10){
		int ans=109;
		sd[0]=1;
		for(int i=1;i<(1<<n);i++){
			int x=0;
			for(int j=1;j<=n;j++){
				if((i>>(j-1))&1){
					x=j;
					break;
				}
			}
			while(!q.empty())q.pop();
			for(int j=1;j<=n;j++)vis[j]=0;
			q.push(x);
			while(!q.empty()){
				int cur=q.front();
				vis[cur]=1;
				q.pop();
				for(int y:a[cur].s){
					if(vis[y]||((i>>(y-1))&1)==0)continue;
					q.push(y);
				}
			}
			sd[i]=1;
			for(int j=1;j<=n;j++){
				if(((i>>(j-1))&1)&&!vis[j]){
					sd[i]=0;
					break;
				}
			}
		}
		for(int i=0;i<(1<<n);i++){
			for(int j=0;j<(1<<n);j++){
				if(((i&j)!=0)||(__builtin_popcount(i)+__builtin_popcount(j)!=k)||!sd[i]||!sd[j])continue;
			//	cout<<i<<' '<<j<<'\n';
				for(int k=1;k<=n;k++)dis[k]=20;
				for(int k=1;k<=n;k++){
					if((i>>(k-1))&1){
						dis[k]=0;
						q.push(k);
					}
				}
				while(!q.empty()){
					int cur=q.front();
					q.pop();
					for(int y:a[cur].s){
						if(dis[y]>dis[cur]+1)dis[y]=dis[cur]+1,q.push(y);
					}
				}
				for(int k=1;k<=n;k++)dis2[k]=20;
				for(int k=1;k<=n;k++){
					if((j>>(k-1))&1){
						dis2[k]=0;
						q.push(k);
					}
				}
				while(!q.empty()){
					int cur=q.front();
					q.pop();
					for(int y:a[cur].s){
						if(dis2[y]>dis2[cur]+1)dis2[y]=dis2[cur]+1,q.push(y);
					}
				}
				int cnt=0;
				for(int k=1;k<=n;k++){
					cnt=max(cnt,min(dis2[k],dis[k]));
				//	cout<<dis[k]<<' '<<dis2[k]<<'\n';
				}
				ans=min(ans,cnt);
			}
		}
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--)Main();
	return 0;
}

