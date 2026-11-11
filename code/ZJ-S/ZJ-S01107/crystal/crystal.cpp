#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,i,a[500010],qzh[500010],ans,mid,t,w;
bool pd(int x){
	int i,tt,ww,sum=0;
	for(i=1;i+x-1<=n;i++){
		tt=i;ww=i+x-2;
		sum=qzh[ww]-qzh[tt-1];
		if(sum<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n-1;i++) qzh[i]=qzh[i-1]+(a[i+1]-a[i]);
	t=1;w=n;
	while(t<=w){
		mid=(t+w)/2;
		if(pd(mid)) ans=mid,t=mid+1;
		else w=mid-1;
	}
	cout<<ans;
}
