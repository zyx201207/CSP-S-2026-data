#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,m,a[N],pre[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=a[i-1]-a[i-2] && i>2){
			flag=false;
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	if(flag){
		int i;
		for(i=n;i>=1;i--){
			if(i*(a[i]-a[1])/2<=m)break;
		}
		cout<<i;
	}
	else{
		int ans=1;
		for(int i=n;i>=1;i--){
			if(ans>i)break;
			int l=1,r=i,mid;
			while(l<r){
				mid=(l+r)/2;
				if(a[i]*(i-mid+1)-pre[i]+pre[mid-1]<=m){
					r=mid;
				}
				else{
					l=mid+1;
				}
			}
			ans=max(ans,i-r+1);
		}
		cout<<ans;
	}
}
