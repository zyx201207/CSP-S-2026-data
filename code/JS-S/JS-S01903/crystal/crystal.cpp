#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],ma,b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		a[i]-=(a[1]-1),b[i]=b[i-1]+a[i];
	}
	for(ll i=1,j=1;i<=n;i++){
		while(a[j]*(j-i)-(b[j-1]-b[i-1])<=m && j<=n){
			j++;
		}
		j--;
		ma=max(ma,j-i+1);
	}
	cout<<ma;
	return 0;
}
