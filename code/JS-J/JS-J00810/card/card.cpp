#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
bool vis[300005];
bool vis2[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		long long ans=0;
		memset(vis,0,sizeof(vis));
		memset(vis2,0,sizeof(vis2));
		for(int j=n;j>=1;j--){
			if(a[j]==i){
				int cnt=j;
				vis2[i]=1;
				while(cnt--){
					ans++;
					if(vis[a[cnt]]&&a[cnt]!=i)break;
					vis2[a[cnt]]=1;
				}
				while(cnt--){
					if(cnt<0)break;
					if(vis2[a[cnt]])ans++;
				}
				cout<<ans<<" ";
				break;
			}
			else{
				vis[a[j]]=1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
