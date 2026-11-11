#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1,zd=a[1],x=0;
	while(r<=n){
		while(r<=n&&x<=m){
			r++;
			x+=(r-l)*(a[r]-zd);
			zd=a[r];
		}
		ans=max(ans,r-l);
		while(l<=r&&x>=m){
			x-=(zd-a[l]);
			l++;
		}
	}
	cout<<ans;
}
