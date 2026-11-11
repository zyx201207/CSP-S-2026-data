#include<bits/stdc++.h>
using namespace std;
int n,a[500005],b[500005],c[500005],ans;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int t=0;
	for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i){
    	if(a[i]>t) t=a[i];
    	b[i]=b[i-1]+a[i];
    	c[i]=t;
	}
	for(int i=1;i<=n;++i){
		int d=(b[i]+m)%i,e=(b[i]+m)/i;
		if(d==0&&c[i]<=e) ans=i;
	}
	cout<<ans;
	return 0;
}