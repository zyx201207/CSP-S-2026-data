#include<bits/stdc++.h>
using namespace std;
long long int c,t,n,d,x[2000010],sum[2000010];
void dfs(int st,int ed,int step){
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int tot=0;
				for(int st=i;st<=j;st++){
					while(sum[st]-sum[i-1]<=d){
						st++;
					}
					st--;
					tot++;
				}
				dfs(i,j,0);
			}
		}
	}
	return 0;
}