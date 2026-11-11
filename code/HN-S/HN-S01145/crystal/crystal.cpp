#include<bits/stdc++.h>
using namespace std;
long long n,m,l=1,ma=1,a[500010],a2[500010];
int main(  ){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		a2[i]=a2[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		while(a[i]*(i-l+1)-(a2[i]-a2[l-1])>m) l++;
		ma=max(ma,i-l+1);
	} 
	cout<<ma;
	return 0;
} 
