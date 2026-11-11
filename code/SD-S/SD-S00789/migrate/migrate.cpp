//Created by Luogu User:951440
#include<bits/stdc++.h>
using namespace std;
int c,T,n,num,ans,stp;
long long d,lst;
long long x[6000];
int dp[6000][6000];
void dfs(int now,int cnt,long long tar) {
	if(x[now]>tar)
		return ;
	if(x[now]==tar) {
		num+=(cnt==stp+1);
		return ;
	}
	if(cnt==stp+1)
		return ;
	int p=upper_bound(x+1,x+1+n,x[now]+d)-x-1;
	for(int i=now+1; i<=p; i++)
		dfs(i,cnt+1,tar);
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--) {
		cin>>n>>d;
		ans=0;
		for(int i=1; i<=n; i++)
			cin>>x[i];
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++)
				for(int k=1; k<=n; k++)
					dp[j][k]=0;
			dp[i][0]=1;
			lst=x[i];
			stp=0;
			for(int j=i+1; j<=n; j++) {
				if(x[j]-x[j-1]>d)
					break;
				if(x[j]-lst>d) {
					stp++;
					lst=x[j-1];
				}
				int p=lower_bound(x+1,x+1+n,x[j]-d)-x;
				p=max(p,i);
				if(n<=9) {
					num=0;
					dfs(i,0,x[j]);
					ans+=(num==2);
				} else {
					for(int k=p; k<j; k++)
						if(stp)
							dp[j][stp]+=dp[k][stp-1];
						else if(x[j]-x[i]<=d)
							dp[j][0]=1;
					if(dp[j][stp]==2) {
						cout<<i<<' '<<j<<' '<<p<<'\n';
						cout<<dp[p][0]<<' '<<dp[j][1]<<'\n';
					}
				}
				ans+=(dp[j][stp]==2);


			}
		}
		cout<<ans<<'\n';
	}
	cout<<endl;
	return 0;
}
//I'm dead.
