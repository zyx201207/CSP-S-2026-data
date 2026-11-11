#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000005],ans,minn,sum,dp[5005][5005],num;
void dfs(int cnt,int now,int end){
	if(now==end){
		if(cnt==minn){
			sum++;
		}else if(cnt<=minn){
			minn=cnt;
			sum=1;
		}
	}
	for(int i=now+1;i<n;i++){
		if(minn==num&&sum>2){
			return ;
		}
		if(x[i]-x[now]<=d){
			dfs(cnt+1,i,end);
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		bool flag=1;
		cin>>n>>d>>x[0]>>x[1];
		int der=x[1]-x[0];
		for(int i=2;i<n;i++){
//			scanf("%lld",&x[i]);
			cin>>x[i];
			if(der!=x[i]-x[i-1]){
				flag=0;
			}
		}
		if(flag){
			int s=d/der;
			if(s<2){
				cout<<0<<endl;
				continue;
			}else{
				s*=2;
				s--;
				if(s>n){
					cout<<0<<endl;
					continue;
				}
				cout<<n-s<<endl;
				continue;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				dp[i][j]=1e9+7;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j-1;k>=0&&x[j]-x[k]<=d;k--){
					dp[i][j]=min(dp[i][j],dp[i][k]+1);
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				sum=0;
				minn=1e9+7;
				num=dp[i][j];
				dfs(0,i,j);
				if(sum==2){
					ans++;
				}
//				cout<<i<<' '<<j<<' '<<sum<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
