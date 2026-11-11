#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,f=1,n,T,d,a[2000010],dp[2000010];
bool check(int x,int y){
	if(a[y]-a[x]<=d)return 0;
	memset(dp,0x3f3f3f3f,sizeof(dp));
	dp[x]=0;
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d){
			dp[i]=1;continue;
		}
		for(int j=i-1;j>x;j--){
			if(a[i]-a[j]>d){
				break;
			}
			dp[i]=min(dp[i],dp[j]+1);
		}
	}
	if(dp[y]==0x3f3f3f3f){
		f=0;
		return 0;
	}
	int cnt=0;
	for(int j=y-1;j>=x;j--){
		if(a[y]-a[j]>d)break;
		if(dp[j]+1==dp[y])cnt++;
	}
	return cnt==2;
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>T;
	while(T--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			int x=a[2]-a[1];
			if(x>=d){
				cout<<0<<"\n";
				continue;
			}
			else{
				if(x*2>d){
					cout<<0<<"\n";
					continue;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				f=1;
				if(check(i,j))ans++;
				if(f==0)break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
