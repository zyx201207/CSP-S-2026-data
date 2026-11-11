#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,cntl,cntr,wl=1,wr;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	wr=n;
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
	}
	cntl=a[1];
	cntr=a[n];
	while(wl<wr){
		if(c[wl]!=c[wr]){
			if(cntl==cntr){
				ans+=cntl;
				wl++;
				wr--;
				cntl=a[wl];
				cntr=a[wr];
			}
			else if(cntl<cntr){
				ans+=cntl;
				cntr-=cntl;
				wl++;
				cntl=a[wl];
			}
			else{
				ans+=cntr;
				cntl-=cntr;
				wr--;
				cntr=a[wr];
			}
		}
		else{
			if(cntl==cntr){
				wl++;
				wr--;
				cntl=a[wl];
				cntr=a[wr];
			}
			else if(cntl<cntr){
				cntr-=cntl;
				wl++;
				cntl=a[wl];
			}
			else{
				cntl-=cntr;
				wr--;
				cntr=a[wr];
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
