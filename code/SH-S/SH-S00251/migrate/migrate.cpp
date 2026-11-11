#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long x[2000001],temp[2000001];
long long ans=2e6,tot=0;
void dfs(int sx,int ex,long long dist,int xx){
	if(xx==ex){
		ans=min(ans,dist);
		temp[++tot]=dist;
	}
	for(int i=xx+1;i<=ex;i++){
		if(x[i]-x[xx]>d) break;
		dfs(sx,ex,dist+1,i);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	while(cin>>c>>t){
		while(t--){
			cin>>n>>d;
			memset(x,0,sizeof(x)); 
			for(int i=1;i<=n;i++) cin>>x[i];
			long long cnt=0;
			for(int i=1;i<=n-3;i++){
				for(int j=i+3;j<=n;j++){
					memset(temp,0,sizeof(temp));
					ans=2e6,tot=0;
					dfs(i,j,0,i);
					sort(temp+1,temp+tot+1);
					int num;
					if(temp[tot]==ans) num=tot;
					else num=upper_bound(temp+1,temp+tot+1,ans)-temp-1;
					if(num==2) cnt++;
				}
			}
			cout<<cnt<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
} 
