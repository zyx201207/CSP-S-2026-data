#include<bits/stdc++.h>
using namespace std;
int n,l,r,b;
long long m,a[500005],ans=0,cf[500005],sum,cnt;
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];

	}
	sort(a+1,a+1+n);
	for(int i=1; i<n; i++) {
		if(a[i+1]>0&&a[i]<0){
			cf[i]=abs(a[i+1]-a[i]);
		}else{
		cf[i]=abs(abs(a[i+1])-abs(a[i]));	
		}
		
		
	}
	cnt=0;l=n-1;sum=1;r=n;
	for(int i=n-1; i>0; i--) {
		for(int j=r-1;j>=i;j--){
			cnt+=cf[j];
		}
		sum++;
		while(cnt>m){
			cnt-=(r-i)*(cf[r-1]);sum--;
			r--;
		}
		
		ans=max(sum,ans);
	}
	cout<<ans;
	return 0;
}

