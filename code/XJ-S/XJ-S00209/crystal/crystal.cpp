#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
long long n,m,a[N],sum[N],ans=1,sum1[N];
long long check(int x){
	int l=1,r=x;
	while(l<r){
		int mid=(l+r)/2;
		if(a[x]*(x-mid)-(sum[x-1]-sum[mid-1])<=m)r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		ans=max(ans,i-check(i)+1);
	}
	cout<<ans;
	return 0;
} 
