#include<bits/stdc++.h>
using namespace std;
const long long int N=500100;
long long a[N],i,n,m,sum[N],d[N],t,h=1,ma=1,ans,k,nex;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	while(h<n){
		while(1){
			nex=t+1;
			k=t-h+1;
			if(nex<=n&&k*a[nex]-(sum[nex-1]-sum[h-1])<=m){
				t++;
				ma=max(ma,k+1);
			}else break;
		}
		h++;
	}
	cout<<ma;
	return 0;
}
