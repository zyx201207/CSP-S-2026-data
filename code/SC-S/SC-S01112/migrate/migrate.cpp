#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,ans;
long long a[1100050];
vector<int>dis[150];
int tot;
int dfs1(int u,int end,int cnt){
	if(a[end]<=a[u]+d){
		cnt++;
		return cnt;
	}
	for(int i=1;i+u<=end;i++){
		if(a[u+i]>a[u]+d){
			dfs1(u+i-1,end,cnt+1);
		} 
	}
}
void dfs2(int u,int end,int cnt){
	if(cnt==0){
		if(u==end){
			tot++;
		}
		return;
	}
	for(int i:dis[u]){
		cnt--;
		dfs2(i,end,cnt);
		cnt++;	
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(n<=9){
			for(int i=1;i<=n;i++){
				dis[i].clear();
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[i]+d>=a[j]){
						dis[i].push_back(j);
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+2;j<=n;j++){
					dfs2(i,j,dfs1(i,j,0));
//					printf("%d|",tot);
					if(tot==1){
						ans++;
						tot=0;
					}
				}
			}
			if(ans==0){
				printf("%d\n",ans);
			}else{
				printf("%d\n",ans-1);
			}
			
		}
	}
} 