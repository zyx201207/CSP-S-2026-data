#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,tot;
ll lth,a[N],l[N],r[N];
char c[N];
void solve(){
	memset(l,0,sizeof l);
	memset(r,0,sizeof r);
	tot=0;
	lth=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int A;
		char C;
		scanf("%d %c",&A,&C);
		lth+=A;
		if(C==c[tot]){
			a[tot]+=A;
			r[tot]+=A;
		}else{
			a[++tot]=A;
			c[tot]=C;
			l[tot]=r[tot-1]+1;
			r[tot]=l[tot]+A-1;
		}
	}
	ll lpos=1,rpos=lth,nlpos=1,nrpos=lth,li=1,ri=tot,ans=0;
	while(li<=tot&&ri>=1&&li<ri&&lpos<=lth&&rpos>=1){
		nlpos=min(r[li],lth-l[ri]+1),nrpos=max(l[ri],lth-r[li]+1);
		if(c[li]!=c[ri]){
			ans+=nlpos-lpos+1;
		}
		lpos=nlpos+1;
		if(lpos>r[li]){
			li++;
		}
		rpos=nrpos-1;
		if(rpos<l[ri]){
			ri--;
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
}
//ccf please let me AC!!!
