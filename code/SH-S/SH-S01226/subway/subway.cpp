#include<bits/stdc++.h>
using namespace std;
int w[500005],cnt=0;
long long dis[5505][5505];
int c,n,m,d,q;
void floyd(){
	int maxn=m+n;
	for(int i=1;i<=maxn;i++){
		for(int j=1;j<=maxn;j++){
			if(dis[i][j]==0){
				if(i!=j)dis[i][j]=1e16;
			}
		}
	}
	for(int i=1;i<=maxn;i++){
		for(int j=1;j<=maxn;j++){
			if(i==j) continue;
			for(int k=1;k<=maxn;k++){
				if(k==i||k==j) continue;
				if(dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	} 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(m>5000) return 0;
	for(int i=1;i<=m;i++) cin>>w[i];
	int k;
	for(int i=1,a;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a;
			cin>>dis[a+n][i];
			dis[i][a+n]=dis[a+n][i];
		}
	}
	int s,t;
	floyd();
	for(int i=1;i<=q;i++){
		cin>>s>>t;
		cout<<dis[s+n][t+n]+w[s]+w[t]<<endl;
	}
	return 0;
}
