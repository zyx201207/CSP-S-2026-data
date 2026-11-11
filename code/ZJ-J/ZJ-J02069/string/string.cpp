#include<bits/stdc++.h>
using namespace std;
int a[200005],n,l=0,r,i=0,j=0;
long long ans=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	r=n-1;
	for(int i=0;i<n;i++) scanf("%d%*c%c",&a[i],&c[i]);
	while(l<r){
		if(c[l]!=c[r]) ans+=min(a[l]-i,a[r]-j);
		if(a[l]-i>a[r]-j) i+=a[r]-j,j=0,r--;
		else if(a[l]-i==a[r]-j) i=0,j=0,l++,r--;
		else j+=a[l]-i,i=0,l++;
	}
	printf("%lld",ans);
	return 0;
}