#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int x,y;
int w[N],a[505][N/2];//t[505][N/2];
int dfs(int q,int st){
	if(st==y) return a[q][st];
	int ans=-1; 
	for(int i=1;i<=n;i++){//第q条铁路的第i站 
		if(a[q][i]==0) continue;
		for(int j=1;j<=n;j++){//换乘到第j条铁路 
			if(a[j][i]!=0){
				ans=min(dfs(j,i)+a[q][i]+a[j][i],ans); 
			} 
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int tmp,tp;
			cin>>tmp>>tp;
			a[i][tmp]=tp;
		}
	}
	while(q--){
		cin>>x>>y;
		int ans=w[x]+w[y];
		int sum=-1;
		for(int i=1;i<=n;i++){
			if(a[i][x]!=0){
				sum=min(dfs(i,x)+a[i][x],sum);
			}
		}
		ans+=sum;
		cout<<ans<<"\n";
	}
	return 0;
}




