#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,t,w,mid,bao,ma,a[500010],b[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(i=1;i<=n;i++){
		t=i;w=n;
		while(t<=w){
			mid=(t+w)/2;
			if(a[mid]*(mid-i)-(b[mid-1]-b[i-1])<=m)
				bao=mid,t=mid+1;
			else w=mid-1;
		}
		ma=max(ma,bao-i+1);
	}
	cout<<ma;
}
