#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[501000],c[501000];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		c[i]=a[i]-a[i-1];
	}
	int l=1,r=1,ans=-1,now=0;
	while(l<=r&&r<=n){
//		cout<<l<<" "<<r<<" "<<now<<"\n";
		if(now+c[r+1]*(r-l+1)<=m){
			r++;
			now+=c[r]*(r-l);
			ans=max(ans,r-l+1);
			if(r>n){
				break;
			}
		}else{
			ans=max(ans,r-l+1);
			now-=(a[r]-a[l]);
//			cout<<r<<"\n";
			l++;
			
		}
	}
	cout<<ans;
} 
