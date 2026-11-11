#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000010],dp[2000010],p[2000010],ls[2000010],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		int j=1;
		memset(ls,0,sizeof(ls));
		for(int i=1;i<=n;i++){
			while(j<=n&&x[j]-x[i]<=d) j++;
			j--;
			if(!ls[j]) ls[j]=i;
		}
		for(int i=n;i>=1;i--){
			if(!ls[i]) ls[i]=ls[i+1];
		}
		if(c==11||c==12){
			memset(dp,0,sizeof(dp));
			dp[1]=1,p[1]=0;
			for(j=1;j<=n;j++){
				int s=0;
				for(int k=ls[j];k<=j;k++){
					if(p[k]!=p[ls[j]]) break;
					s+=dp[k];
					if(s>2) break;
				}
				dp[j]=min(s,3ll);
				p[j]=p[ls[j]]+1;
				if(dp[j]==2) ans+=n-j+1;
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			memset(dp,0,sizeof(dp));
			dp[i]=1,p[i]=0;
			for(j=i+1;j<=n;j++){
				int s=0;
				for(int k=max(ls[j],i);k<=j;k++){
					if(p[k]!=p[max(ls[j],i)]) break;
					s+=dp[k];
					if(s>2) break;
				}
				dp[j]=min(s,3ll);
				p[j]=p[max(ls[j],i)]+1;
				if(dp[j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
