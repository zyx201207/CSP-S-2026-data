#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,l,r,a[N];
long long ans,zx;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(l<r){
		zx=min(a[l],a[r]);
		a[l]-=zx;
		a[r]-=zx;
		if(c[l]!=c[r])ans+=zx;
		if(!a[l])l++;
		if(!a[r])r--;
	}
	printf("%lld",ans);
	return 0;
	
}
