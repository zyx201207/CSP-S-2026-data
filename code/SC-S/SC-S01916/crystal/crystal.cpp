#include<bits/stdc++.h>
using namespace std;

long long a[500005];
long long sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	memset(sum,0,sizeof(sum));
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i] = sum[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	int l = 1,r = 2;
	long long k,maxn = -1;
	while(l<n&&r<=n){
		k = sum[r]-sum[l]-(a[r]-a[l])*(l-1);
		if(k>m){
			l++;
		}
		else{
			maxn = max(maxn,(long long)r-l+1);
			r++;
		}
	}
	cout<<maxn;
	return 0;
	
}