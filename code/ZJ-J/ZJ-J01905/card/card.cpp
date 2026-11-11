#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[500005],dis[300005],t[300005];
int g[500005];
bool f[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int e=1;e<=n;e++){
		for(int i=e;i<=n;i++){
			if(f[a[i]]==1){
				for(int j=t[a[i]]+1;j<=k;j++)f[g[j]]=0;
				k=t[a[i]];
			}
			else {
				g[++k]=a[i];
				f[a[i]]=1;
				t[a[i]]=k;
			}
		}
		/*for(int i=1;i<=k;i++)cout<<g[i]<<"  ";
		cout<<"\n\n";*/
		for(int i=1;i<=k;i++)dis[g[i]]++;
		k=0;
		memset(f,0,sizeof(f));
	}
	for(int i=1;i<=m;i++)cout<<dis[i]<<" ";
	return 0;
}