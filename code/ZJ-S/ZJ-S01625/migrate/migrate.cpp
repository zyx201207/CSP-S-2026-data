#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
const int N=2e6+5;
int n,d,a[N];
struct node{
	int v,o;
};
bool dfs(int x,int y){
	vector<int> df(n+1,n+1);
	vector<int> dp(n+1,0);
	df[x]=0;
	dp[x]=1;
	for(int i=x+1;i<=y;i++){
		int o=n+1,p=0;
		for(int j=i-1;j>=x;j--){
			if(a[i]-a[j]<=d){
				if(df[j]+1==o){
					p+=dp[j];
				}
				if(df[j]+1<o){
					o=df[j]+1;
					p=dp[j];
				}
			}else{
				break;
			}
		}
		df[i]=o;
		dp[i]=p;
	}
	if(dp[y]==2){
		return 1;
	}else{
		return 0;
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<=5000){
			int ans=0;
			for(int p=1;p<=n;p++){
				for(int q=1;q<=p;q++){
					if(dfs(q,p)) ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
