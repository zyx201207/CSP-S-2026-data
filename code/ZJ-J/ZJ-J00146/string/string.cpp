#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %c",&a[i],&c[i]);
	int l=1,r=n;
	ll ans=0;
	while(l<r){
		if(a[l]==a[r]){
			if(c[l]!=c[r]) ans+=a[l];
			l++,r--;
		}
		else if(a[l]<a[r]){
			if(c[l]!=c[r]) ans+=a[l];
			a[r]-=a[l]; l++;
		}
		else if(a[l]>a[r]){
			if(c[l]!=c[r]) ans+=a[r];
			a[l]-=a[r]; r--;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
