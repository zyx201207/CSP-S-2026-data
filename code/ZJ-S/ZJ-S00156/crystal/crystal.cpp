#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll max(ll x,ll y){
	if(x>y)return x;
	else return y;
}
ll n,m,i,a[1000001],j,flag,ma,b[1000001],ba,tal[1000001];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i],ma=max(ma,a[i]);
	sort(a+1,a+n+1);
	for(i=2;i<=n;i++)tal[i]=(a[i]-a[i-1])*(i-1)+tal[i-1];
	if(n<=5000){
		for(i=1;i<=n;i++)b[i]=a[i]+b[i-1];
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++){
				flag=tal[j]-(a[j]*(i-1)-b[i-1]);
				if(flag<=m){
				
					ba=max(ba,j-i+1);
				}
			}
	}else if(n>5000){
		for(i=1;i<=n;i++)
			if(tal[i]<=m)ba=i;
	}
	cout<<ba;
	return 0;
	//freopen("1145.in","r",stdin);
	//80tps
	// 666Ì«ÄÑÁË 
}
