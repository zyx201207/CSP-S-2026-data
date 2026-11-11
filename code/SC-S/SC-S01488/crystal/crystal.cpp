#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e5+10;
long long a[N];
//int best[N];
int n;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int lp=1,rp=1,ans=0;
	long long sum=0;
	for(;rp<=n;rp++){//rp++
		sum+=(rp-lp)*(a[rp]-a[rp-1]);
		while(sum>m){
			sum-=(a[rp]-a[lp]);
			lp++;
		}
		ans=max(ans,rp-lp+1);
	}
	cout<<ans<<"\n";
	return 0;
}