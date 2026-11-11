#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=500500;
int n,ans;
ll m;
ll a[M],c[M];
ll b[M];
void mer(int li,int ri){
	if(li==ri) return;
	int mi=(li+ri)>>1;
	mer(li,mi);
	mer(mi+1,ri);
	int j=mi+1,t=li;
	for(int i=li;i<=mi;i++){
		while(a[j]<a[i]&&j<=ri){
			c[t++]=a[j];
			j++;
		}
		c[t++]=a[i];
	}
	while(j<=ri){
		c[t++]=a[j];
		j++;
	}
	for(int i=li;i<=ri;i++) a[i]=c[i];
}
bool ch(int xx,int yy){
	ll co=(ll)a[yy]*(yy-xx+1)-(b[yy]-b[xx-1]);
	if(co<=m) return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	mer(1,n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
		int l=1,r=i;
		while(l<r){
			int midd=(l+r)>>1;
			if(ch(midd,i)) r=midd;
			else l=midd+1;
		}
		ans=max(ans,i-l+1);
	}
	printf("%d",ans);
	return 0;
}