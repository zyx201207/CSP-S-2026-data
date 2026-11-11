#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N],vis[M],ans[N],sum[M];
int cnt=0;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		cnt=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				ans[++cnt]=a[j];
				vis[a[j]]=cnt;
			}else{
				int pos=vis[a[j]];
				for(;cnt>pos;--cnt){
					vis[ans[cnt]]=0;
				}
			}
		}
		for(int k=1;k<=cnt;k++){
			sum[ans[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",sum[i]);
	}
	return 0; 
}
