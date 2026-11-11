#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[1000006],b[1000006];
int maxn=1,sum,l,r;
signed main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		b[i-1]=a[i]-a[i-1];
	}
	l=1,r=1;
	while(r<n){
		while(sum+(r-l+1)*b[r]<=k&&r<=n-1){
			sum+=(r-l+1)*b[r];
			r++;
		}
		maxn=max(maxn,r-l+1);
		sum-=(a[r]-a[l]);
		l++;
	}
	cout<<maxn<<endl;
	return 0;
}

