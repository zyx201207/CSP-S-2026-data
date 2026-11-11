#include<bits/stdc++.h>
using namespace std;
long long i,n,m,ma,a[500010],ans[500010],t,w,mid,bao;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	ans[1]=0;
	for(i=2;i<=n;i++)
		ans[i]=ans[i-1]+(i-1)*(a[i]-a[i-1]);
	for(i=1;i<=n;i++){
		t=1;w=n-1;bao=n;
		while(t<=w){ 
			mid=(t+w)/2;
			if(ans[i]-ans[mid]-(mid-1)*(a[i]-a[mid])<=m)bao=mid,w=mid-1;
			else t=mid+1;
		} 
		ma=max(ma,i-bao+1);
	}	
	cout<<ma;
	return 0;
}