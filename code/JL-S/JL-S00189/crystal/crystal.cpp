#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],s[N];
bool check(int x,int y){
	int tot=s[y]-s[x-1];
	int len=y-x+1;
	int cnt=a[y+1]*len-tot;
	//if(y==4) cout<<cnt;
	if(cnt<=m) return 1;
	else return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	s[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=0,r=i-1;
		while(l+1<r){
			//cout<<l<<' '<<r<<endl;
			int mid=(l+r)>>1;
			if(check(mid,i-1)==1){
				r=mid;
				//if(i==5) cout<<mid<<endl;
			}else l=mid;
		}
		ans=max(ans,i-r+1);
	}
	printf("%lld\n",ans);
	return ~(-1);
}
//crystal
/*
5 8
-3 -1 2 2 7
*/
//ji ba zhe ci de1 bu fen fen zen me dou zhe me bu hao xie
// T2 T3 T4 dou shi rngdle shui beng de zhu
//gan jue T3 8 fen ying gai mei wen ti T2 44 fen ke neng you hen da wen ti
//T4 15 fen bu zhi dao wei shen me di er ge yang li RE le,di yi ge guo de
//ai jiu zhe yang ba,zhi qiu T1 bu gua,ni gei wo 100 fen wo dou ren le