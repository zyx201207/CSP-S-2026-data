#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,m;
int a[5000005];
int ma[5000005];
int maxn,ans;
int jishu;
bool keyi=1;
int chada=0;
void dfs(int x,int y,int ge){
	if(x==ma[x]&&x!=y){
		keyi=1;
		return ;
	}
	for(int i=ma[x];i>=x+1;i--){
		if(i>=y){
			if(maxn==ge){
				jishu++;
			}
			else if(maxn>ge){
				if(maxn!=INT_MAX)chada=max(chada,maxn-ge);
				maxn=ge;
				jishu=1;
			}
			if(jishu==3)keyi=1;
			return ;
		}
		dfs(i,y,ge+1);
		if(keyi)return ;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			int tou=i,wei=n;
			while(tou<=wei){
				int mid=(tou+wei)/2;
				if(a[mid]<=m+a[i]){
					tou=mid+1;
					ma[i]=mid;
				}
				else wei=mid-1;
			}
		}
		for(int i=1;i<=n;i++){
			bool t=0;
			for(int j=ma[i]+1;j<=n;j++){
				if(t)break;
				if(j==n)t=1;
				
				maxn=INT_MAX;
				keyi=0;
				jishu=0;
				dfs(i,j,0);
				if(jishu==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
