#include<bits/stdc++.h>
using namespace std;
const long long INF=100000005;
long long amap[1000005][1000005];
long long ans[1000005];
void init(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			amap[i][j]=INF;
		}
	}
	//long long ans=INF;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		amap[u][v]=amap[v][u]=1;
	}
	for(int k=1;k<=n;k++){
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				amap[i][j]=min(amap[i][j],amap[i][k]+amap[j][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(amap[i][j]>ans[i]){
				ans[i]=amap[i][j];
			}
		}
	}
	sort(ans+1,ans+n+1);
	if(k==2)cout<<ans[1]+ans[2]<<endl;
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)init();
	return 0;
}