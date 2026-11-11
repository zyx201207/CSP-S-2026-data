#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],ans,tot;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l,r;
	long long t=m;
	l=r=1;
	while(l<=n&&r<=n&&l<=r){
		long long len=r-l+1;
		ans=max(ans,len);
		if(len*(a[r+1]-a[r])<=t){
			t-=len*(a[r+1]-a[r]);
			r++;
		}else{
			t+=(a[r]-a[l]);
			l++;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
