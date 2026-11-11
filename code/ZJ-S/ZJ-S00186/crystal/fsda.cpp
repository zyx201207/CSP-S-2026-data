#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long a[N],t[N];
long long n,m;
long long res;
int main(){
	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		long long z=m;
		long long ans=0;
		for(long long j=i;j>=1;j--){
			if(z>=a[i]-a[j]){
				z-=(a[i]-a[j]);
				ans++;
			}
		}
		if(ans>res){
			res=ans;
//			cout<<i<<'\n';juewang
		}
	}
	cout<<res<<' ';
	return 0;
}
