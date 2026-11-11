#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,h[500010],a[500010],ma=1,t,w,mid,bao;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++) h[i]=h[i-1]+a[i];
	for(i=n;i>=1;i--){
		if(i*a[i]-h[i]<=m) ma=max(ma,i);
		else{
			t=1;w=i-1;bao=i;
			while(t<=w){
				mid=(t+w)/2;
				if((i-mid+1)*a[i]-h[i]+h[mid-1]<=m) bao=mid,w=mid-1;
				else t=mid+1;
			}
			ma=max(ma,i-bao+1);
		}
	}
	cout<<ma;
	return 0;
}