#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+5;
int c,T,n,dp[N],num[N];
ll d,x[N],ans;
inline void sol1(){
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			dp[j]=1e9;
			num[j]=1;
		}
		dp[i]=0;
		for(int j=i;j<=n;j++){
			ll pre=x[j+1]-x[j];
			for(int k=j+1;k<=n;k++){
				if(pre>d)break;
				if(dp[j]+1<dp[k]){
					dp[k]=dp[j]+1;
					num[k]=1;
				}else if(dp[j]+1==dp[k])num[k]++;
				pre+=x[k+1]-x[k];
			}
		}
		for(int j=i+1;j<=n;j++){
			if(num[j]==2)ans++;
		}
	}
	cout<<ans<<'\n';
}
inline void sola(){
	if(x[2]-x[1]>d){
		cout<<"0\n";
		return;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(i+d+1>n)break;
		ans+=n-i-d-(n-i)/d+1;
	}
	cout<<ans<<'\n';
}
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n==1){
			cout<<"0\n";
			continue;
		}
		if(c==11||c==12)sola();else sol1();
		//sol1();
	}
	return 0;
}
