#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%s",a+i,c+i);
	}
	int l=1,r=n;
	while(l<r){
		int t=min(a[l],a[r]);
		if(c[l]!=c[r]){
			ans+=t;
		}
		a[l]-=t;
		a[r]-=t;
		if(a[r]<=0){
			r--;
			a[r]+=a[r+1];
		}if(a[l]<=0){
			l++;
			a[l]+=a[l-1];
		}
	}
	printf("%lld\n",ans);
	return 0;
}
