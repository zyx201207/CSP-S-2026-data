#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],n,m,mx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1,ans=0,mx=0;
	while(l<=r&&r<n){
		ans=((a[r+1]-a[r])+(a[r+1]-a[l]))*(r-l+1)/2;
		if(ans<=m)mx=max(r+1-l+1,mx);
		if(ans>m)l++;
		else r++;
	}
	mx=max(r+1-l+1,mx);
	cout<<mx;
	return 0;
}

