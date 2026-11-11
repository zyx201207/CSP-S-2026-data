#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005],c;
long long s[1000005];
int mmax=INT_MIN;
int l=1,r=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	while(r<n){
		while(r>l&&c>m){
			c-=(a[r]-a[l]);
			l++;
		}
		r++;
		s[r]=a[r];
		c+=(r-l)*(a[r]-a[r-1]);
		if(c<=m)mmax=max(mmax,r-l+1);
	}
	cout<<mmax;
	return 0;
} 
