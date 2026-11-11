#include<bits/stdc++.h>
using namespace std;
int n;
int l,r;
long long ans,minx;
int a[200005];
char ch[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%s",&a[i],&ch[i]);
	l=1;
	r=n;
	while(l<r){
		minx=min(a[l],a[r]);
		if(ch[l]==ch[r]){
			a[l]-=minx;
			a[r]-=minx;
			if(!a[l])l++;
			if(!a[r])r--;
			continue;
		}
		ans+=1ll*minx;
		a[l]-=minx;
		a[r]-=minx;
		if(!a[l])l++;
		if(!a[r])r--;
	}
	printf("%lld",ans);
	return 0;
}


