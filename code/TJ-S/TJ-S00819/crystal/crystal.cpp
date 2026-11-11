#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=1,r=2,sum=0;
	while(r<=n){
		sum+=(a[r]-a[r-1])*(r-l);
		if(sum>m){
			ans=max(ans,r-l);
			sum-=a[r]-a[l];
			l++;
		}
		r++;
	}
	ans=max(ans,r-l);
	cout<<ans;
	return 0;
}

