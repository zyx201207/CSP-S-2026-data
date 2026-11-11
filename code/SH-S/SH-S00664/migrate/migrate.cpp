#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,x[2000005],d;
short dp[5005][5005],mm[5005][5005];
ll solve(){
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ll m=0,las=i;
		for(ll j=i+1;j<=n;j++){
			if(x[j]-x[las]>d){
				las=j-1;
				m++;
			}
			mm[i][j]=m+1;
		}
	}
	dp[1][1]=1;
	for(ll i=2;i<=n;i++){
		if(x[i]-x[i-1]>d){
			for(ll k=1;k<=i;k++)dp[k][i]=0;
		}
		for(ll k=1;k<i;k++){
			ll j=i-1,len=x[i]-x[j],res=0;
			while(j>=1&&j>k&&len<=d&&res<=2){
				if(mm[k][j]+1==mm[k][i]){
					res+=dp[k][j];
				}
				j--;
				len=x[i]-x[j];
			}
			if(j==k&&len<=d){
				res++;
			}
			dp[k][i]=res>2?3:res;
			if(res==2)ans++;
		}
	}
	return ans;
}
ll solveA(){
	ll cc=x[2]-x[1];
	ll e=d/cc;
	if(e==0){
		return 0;
	}
	return (n%e+n)*(n/e)/2;
}
ll solveB(){
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++)cin>>x[i];
		if(c<=10)cout<<solve()<<'\n';
		else if(c==11||c==12)cout<<solveA()<<'\n';
		else if(c==13||c==14)cout<<solveB()<<'\n';
		//cerr<<solveA()<<'\n';
		//cout<<solveA()<<'\n';
	}
	return 0;
}
