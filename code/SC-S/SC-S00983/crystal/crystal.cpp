#include<bits/stdc++.h>
using namespace std;
long long a[555555],p[55555],f[555555],n,m,sum=0,l,r,mx=-1145141;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
    	f[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
    	p[i]=p[i-1]+f[i];
	}
	for(int i=1;i<=n;i++){
    	f[i]=a[i]-a[i-1];
	}
	l=1;r=1;
	while(r<=n){
		if((r-l)>=mx&&sum<=m){
			mx=r-l+1;
		}
		if(sum<=m){
			r++;
			sum+=(r-l)*f[r];
		}else{
			l++;
			sum-=(p[r]-p[l-2]);
		}
	}
	cout<<mx;
	return 0;
}