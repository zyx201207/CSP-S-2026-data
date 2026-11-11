#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2000005;
int c,t,n,d,x[maxn],ans,R[maxn],L[maxn],sumL[maxn],sumR[maxn];
namespace dhcio{
	inline int read(){
		char ch=getchar();int ret=0,f=1;
		while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
		while(ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
		return ret*f;
	}
	inline void write(int x){
		if(x<0) x=-x,putchar('-');
		if(x>9) write(x/10);
		putchar('0'+x%10);
	}
}
using namespace dhcio;
void init(){
	ans=0;
	for(int i=1;i<=n;i++) L[i]=R[i]=sumL[i]=sumR[i]=0;
}
int calc(int L1,int R1,int L2,int R2){
	if(L1>R1||L2>R2) continue;
	
}
void solve(){
	n=read(),d=read();init();
	for(int i=1;i<=n;i++) x[i]=read();
	int last=1;
	for(int i=1;i<=n;i++){
		while(last<n&&x[last+1]-x[i]<=d) last++;
		R[i]=last;
	}
	last=n;
	for(int i=n;i>=1;i--){
		while(last>1&&x[i]-x[last-1]<=d) last--;
		L[i]=last;
	}
	for(int i=1;i<=n;i++){
		sumL[i]=1;
		if(L[i]==i) continue;
		if(R[L[i]]!=i) continue;
		int l=L[i],r=i-1,mid,now=L[i];
		while(l<=r){
			mid=l+r>>1;
			if(R[mid]==i) now=mid,l=mid+1;else r=mid-1;
		}
		sumL[i]+=sumL[L[i]]+now-L[i];
	}
	for(int i=1;i<=n;i++) printf("%d ",sumL[i]);putchar('\n');
	for(int i=n;i>=1;i--){
		sumR[i]=1;
		if(R[i]==i) continue;
		if(L[R[i]]!=i) continue;
		int l=i+1,r=R[i],mid,now=R[i];
		while(l<=r){
			mid=l+r>>1;
			if(L[mid]==i) now=mid,r=mid-1;else l=mid+1;
		}
		sumR[i]+=sumR[R[i]]+R[i]-now;
	}
	for(int i=1;i<=n;i++) printf("%d ",sumR[i]);putchar('\n');
	for(int i=2;i<n-1;i++){
		int x=i,y=i+1;
		if(R[x]==y||R[x]==x) continue;
		if(L[y]==x||L[y]==y) continue;
		int sL=0,sR=0;
		printf("%d %d\n",R[x],R[y]);
		if(R[x]<R[y]){
			sR=R[x]-y;
		}else{
			sR=R[x]-1-y+sumR[R[x]];
		}
		if(L[x]<L[y]){
			sL=x-L[y];
		}else{
			sL=x-L[x]-1+sumL[L[x]];
		}
		ans+=sL*sR;
		ans-=calc(L[y]+1,x-1,y+1,R[x]-1);
		printf("%d %d %d %d\n",x,y,sL,sR);
	}
	write(ans),putchar('\n');
}
signed main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--) solve();
	return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/
