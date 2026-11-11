#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ans;char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		a[i]=a[i-1]+a[i];
	}
	int l=1,r=a[n],L=1,R=n;
	while(l<=a[n]/2){
		int d1=min(a[L],a[n]/2)-l+1;
		int d2=r-max(a[R-1],(a[n]+2)/2);
		bool f=(c[L]!=c[R]);
		if(d1==d2){
			l+=d1,r-=d2;
			L++,R--;
			ans+=d1*f;
		}
		if(d1<d2){
			l+=d1,r-=d1;
			L++;
			ans+=d1*f;
		}
		if(d1>d2){
			l+=d2,r-=d2;
			R--;
			ans+=d2*f;
		}
	}
	cout<<ans;
	return 0;
}
