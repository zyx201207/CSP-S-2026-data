#include<bits/stdc++.h>
using namespace std;
long long C,T,n,d,x[2000005],dp[2000006],f[15];
void dfs(int sum,int num,int o){
	if(sum==o){
		f[num]++;
		return ;
	}
	for(int i=sum+1;i<=o;i++){
		if(x[i]-x[sum]>d)break;
		dfs(i,num+1,o);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(C==1||C==2){
			long long ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					if(x[j]-x[j-1]>d)break;
					for(int i=1;i<=n;i++)f[i]=0;
					dfs(i,0,j);
					for(int i=1;i<=n;i++){
						if(f[i]>0){
							if(f[i]==2)ans++;
							break;
						}
					}
					
				}
			}
			cout<<ans<<"\n";
		}
		else{
			cout<<0<<"\n";
		}
		
	}
	return 0;
}
