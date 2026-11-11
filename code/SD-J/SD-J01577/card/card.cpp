#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N],b[N];
struct gyuf{
	int w;
	bool y;
}vis[N];
signed main(){	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)vis[j].y=0,vis[j].w=0;
		memset(b,0,sizeof(b));
		int len=0;
		for(int j=i;j<=n;j++){
			b[++len]=a[j];
			if(vis[a[j]].y&&vis[a[j]].w<len){
				len=vis[a[j]].w;
				for(int k=len;k<=m;k++)vis[k].y=0,vis[j].w=0;
			}else{
				vis[a[j]].y=1;
				vis[a[j]].w=j;
			}
		}
		for(int j=1;j<=len;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
} 

