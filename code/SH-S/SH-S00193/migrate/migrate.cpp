#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
long long cnt[2000005];
long long x[2000005],ans;
void dfs(int u,int f,int sum){
	if(u==f){
		cnt[sum]++;
		return;
	}
	if(u==n)return;
	int v=u;
	while(v<n&&x[v+1]-x[u]<=d){
		v++;
		dfs(v,f,sum+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				memset(cnt,0,sizeof(cnt));
				dfs(i,j,0);
				for(int k=1;k<=j-i;k++){
					if(cnt[k]!=0){
						if(cnt[k]==2){
							ans++;
						}
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
