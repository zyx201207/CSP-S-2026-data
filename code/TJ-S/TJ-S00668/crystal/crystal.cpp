#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long num=0,r=1,l=1;
	while(1){
		if(r>=n&&l>=n)break;
		ans=max(ans,r-l+1);
		if(r<n&&num+(r-l+1)*(a[r+1]-a[r])<=m){
			num+=(r-l+1)*(a[r+1]-a[r]);
			r++;
		}
		else if(r>l){
			l++;
			num-=a[r]-a[l];
		}
		else{
			num=0;
			l++;
			r++;
		}
	}
	cout<<ans;
	return 0;
}
