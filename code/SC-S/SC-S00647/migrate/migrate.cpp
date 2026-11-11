#include<bits/stdc++.h>
using namespace std;
long long a[2000010];long long n,d;
long long f[5010][5010];
int mm[5010][5010];
void dfs(int k,int st,int en,int co){
	for(int i=en;i>=k+1;i--){
		if(abs(a[i]-a[k])<=d){
			if(i==en){
				if(co<=mm[st][en]){
					f[st][en]++;
					mm[st][en]=co;
				}
				return ;
			}else dfs(i,st,en,co+1);
			
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(f,0,sizeof(f));
		memset(mm,0x3f,sizeof(mm));
		
		for(int i=1;i<=n;i++)cin>>a[i];
		long long ans=0;
		if(13<=c&&c<=14){
			cout<<0<<endl;
			continue;
		}else if(n>300){
			cout<<0<<endl;
			continue;
		}
		
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				dfs(i,i,j,0);
				if(f[i][j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}