#include<iostream>
using namespace std;

int c,t,n,d;
long long a[310];
long long ans;
pair<long long,long long>dp[310][310];
long long lb(long long l,long long r,long long x){
	while(l<r){
		long long mid=l+r>>1;
		if(a[mid]>=x)r=mid;
		else l=mid+1;
	}
	return l;
}
long long f(){
	long long cnt=0;
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(j==i){
				dp[i][i]={1,0};
				continue;
			}
			long long x=lb(i,j,a[j]-d);
			pair<long long,long long>p;
			p.first=dp[i][x].first;
			p.second=dp[i][x].second; 
			for(long long k=x+1;k<j;k++){
				if(dp[i][k].second==p.second)p.first+=dp[i][k].first;
				if(dp[i][k].second<p.second){
					p.first=dp[i][k].first;
					p.second=dp[i][k].second;
				}
			}
			dp[i][j].first=p.first;
			dp[i][j].second=p.second+1;
			if(dp[i][j].first==2)cnt++;
		}
	}
	return cnt;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=6){
		while(t--){
			cin>>n>>d;
			for(long long i=1;i<=n;i++){
				cin>>a[i];
			}
			ans=f();
			cout<<ans<<endl;
		}
	}
	return 0;
} 
