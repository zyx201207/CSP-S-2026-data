#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],p[N],add[N],now=0,l=1,r=1,ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		p[i]=a[i]-a[i-1];
	}
	while(r<=n && l<=r){
		now+=(r-l)*p[r];
		while(now>m){
			l++;
			now-=a[r]-a[l];
		}
		ans=max(ans,r-l+1);
//		cout<<l<<' '<<r<<' '<<now<<endl;
		r++;
	}
	cout<<ans;
	return 0;
} 
