#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],b[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		a[i]-=a[1];
	}
	a[1]=0;
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	int l=1,r=2;
	while(1){
		while(a[r]*(r-l)-b[r-1]+b[l]<=m&&r<=n){
			r++;
		}
		if(r>n||l>n){
			break;
		}
		ans=max(ans,r-l);
		l++;
	}
	cout<<ans;
	return 0;
}