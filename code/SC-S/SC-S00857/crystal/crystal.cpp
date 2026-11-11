#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],cnt,mx=-1e9,b[500005][2];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
memset(b,0,sizeof(b));
sort(a+1,a+n+1);
for(int i=1;i<=n;i++){
	b[i][0]+=b[i-1][0]+a[i];
	b[i][1]=a[i]*i-b[i][0];
}
for(ll i=1;i<=n;i++){
	for(ll j=0;j<i;j++){
		if(b[i][1]+b[j][0]<=m){
			mx=max(mx,i-j);
		}
	}
}
cout<<mx;
	return 0;
}
