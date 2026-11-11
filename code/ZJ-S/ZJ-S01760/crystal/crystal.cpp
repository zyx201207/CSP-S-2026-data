#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[5000001];
int main(){
	freopen("r","crystal.in",stdin);
	freopen("w","crystal.out",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long sum=0,ans=0,cnt=1,f=1;
	for(int i=2;i<=n;i++){
		sum+=cnt*(a[i]-a[i-1]);
		cnt++;
		while(sum>m){
			cnt--;
			sum-=(a[i]-a[f]);
			f++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
}
