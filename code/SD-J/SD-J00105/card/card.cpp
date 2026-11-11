//operater
//priority
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
int n,a[N],z[N],vis[N],m,to[N],ans[N],l[N],r[N],ne[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		to[i]=vis[a[i]];
		ne[vis[a[i]]]=i;
		vis[a[i]]=i;
	} 
	to[0]=0;
	for(int i=0;i<=m;i++)vis[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[j])continue;
			if(!vis[to[j]]&&to[j]>=i){
				for(int k=to[j];k<j;k++)vis[k]=1,to[ne[j]]=to[j];
			}
		}
		for(int j=1;j<=n;j++){
			if(!vis[j])ans[j]++;
			vis[j]=0;
		}
		
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
} 
