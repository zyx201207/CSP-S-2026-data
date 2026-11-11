#include<bits/stdc++.h>

using namespace std;
const int N=5e5+5;
long long n,m,a[N];

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	long long ans=1;
	long long sum=0,rk=1;
	for(int i=2;i<=n;++i){
		sum+=(a[i]-a[i-1])*(i-rk);
		//cout<<sum<<' ';
		while(sum>m&&rk<=i){
			sum-=(a[i]-a[rk]);
			rk++;
		}
		ans=max(ans,i-rk+1);
		//cout<<i<<' '<<i-rk+1<<' '<<sum<<' '<<rk<<endl;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int TEST=1;
	//cin>>TEST;
	while(TEST--)
		solve();
	return 0;
} 
