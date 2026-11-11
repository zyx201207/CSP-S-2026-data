#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
struct node{
	int x;
	int w;
} a[N];
int p[32];
int logg[32];
bool ep[N][32];
int high[N];
bool cmp(node x,node y) {
	if(high[x.w]!=high[y.w]) return high[x.w]>high[y.w];
	for(int i=0;i<=high[x.w];i++){
		if(ep[x.w]&&!ep[y.w]) return true;
		if(ep[y.w]&&!ep[x.w]) return false;
	}return true;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	logg[0]=1;
	for(int i=1; i<=30; i++) logg[i]=2*logg[i-1];
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i].x);
		a[i].w=i;
		int v=a[i].x,p_now=30;
		while(v) {
			if(logg[p_now]<=v) {
				high[i]=max(high[i],p_now);
				ep[i][p_now]=true;
				p[p_now]+=1;
				v-=logg[p_now];
			}
			p_now-=1;
		}
	}
	sort(a+1,a+1+n,cmp);
	int np=0;
	for(int i=32;i>=0;i--){
		if(p[i]>=m){
			np=i;
			break;
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		if(i+m-1>n) continue;
		if(a[i].x <logg[np]||a[i+m-1].x <logg[np]) continue;
		int sum=a[i].x ;
		for(int j=i+1;j<=i+m-1;j++){ 
			sum=sum&a[j].x;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}