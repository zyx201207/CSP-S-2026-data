#include<bits/stdc++.h>
#define cmin(a,b) a=std::min(a,b)
#define cmax(a,b) a=std::max(a,b)
#define inf
#define mod
#define maxn 1000006
#define int long long
#define pb push_back
#define pii std::pair<int,int>
#define arr(x) std::array<int,(x)>
#define fi first
#define se second
bool Mst;
int n,m,a[maxn];
void ama10(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	std::sort(a+1,a+n+1);
	int l=1,res=0,ans=0;
	for(int r=1;r<=n;r++){
		while(res>m){
			res-=a[r]-a[l],l++;
		}
		cmax(ans,r-l+1);
		if(r!=n) res+=(a[r+1]-a[r])*(r-l+1);
	}
	printf("%lld\n",ans);
}
bool Med;
signed main(){
//	fprintf(stderr,"used: %lld MB\n",(&Med-&Mst)/1024/1024);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ama10();
	return 0;
}
/*
-std=c++14 -O2 -lm -Wall -Wl,--stack=1234567890
14:30
W 14:34
crystal.exe < crystal1.in > 1.out
crystal.exe < crystal2.in > 2.out
crystal.exe < crystal3.in > 3.out
crystal.exe < crystal4.in > 4.out
fc 1.out crystal1.ans
fc 2.out crystal2.ans
fc 3.out crystal3.ans
fc 4.out crystal4.ans
*/


