#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200005
int a[maxn],n;
char c[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d %c",a+i,c+i);
	ll ans=0;
	for(int l=1,r=n;l<r;){
		if(c[l]==c[r]){
			int k=min(a[l],a[r]);
			a[l]-=k,a[r]-=k;
			if(a[l]==0)l++;
			if(a[r]==0)r--;
		}else{
			int k=min(a[l],a[r]);
			ans+=k,a[l]-=k,a[r]-=k;
			if(a[l]==0)l++;
			if(a[r]==0)r--;
		}
	}
	printf("%lld",ans);
	return 0;
}
