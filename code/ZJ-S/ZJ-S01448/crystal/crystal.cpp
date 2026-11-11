#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,a[500010],b[500010],t,w,bao,mid,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(i=1;i<=n;i++){
		t=1;w=i;bao=i;
		while(t<=w){
			mid=(t+w)/2;
			if(a[i]*(i-mid+1)-b[i]+b[mid-1]<=m) bao=mid,w=mid-1;
			else t=mid+1; 
		}
		ans=max(ans,i-bao+1);
	}
	cout<<ans;
}