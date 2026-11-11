#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=1,r=0,now=0,ans=0;
	while(r<n){
		r++;
		if(a[r]!=a[r-1])now+=(r-l)*(a[r]-a[r-1]);
		while(now>k){
			now-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}
