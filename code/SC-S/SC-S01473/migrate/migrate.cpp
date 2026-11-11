#include<bits/stdc++.h>
using namespace std;
int n,m,c,T;
int a[5007],s[5007][5007];
int dfs(int u,int goal,int step){
	if(step==-1){
		return 0;
	}
	if(u==goal){
		return 1;
	}
	int sum=0;
	for(int i=u+1;i<=goal;i++){
		if(s[u][i]){
			sum+=dfs(i,goal,step-1);
		} 
	}
	return sum;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		memset(s,0,sizeof(s));
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=m){
					s[i][j]=1;
				}else break;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=1;k<=j-i;k++){
					int temp=dfs(i,j,k);
					if(temp==2){
						ans++;
						break;
					}else if(temp==1){
						break;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}