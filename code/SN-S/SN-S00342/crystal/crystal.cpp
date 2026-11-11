//汤佳忆 西安辅轮中学 SN-S00432 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],maxn=-1e18;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=1,ans=0,cnt=0,cy=1;
	while(r!=n){
		int x=cnt+cy*(a[r+1]-a[r]);
		if(x<=m){
			r++;
			cnt+=cy*(a[r]-a[r-1]);
			cy++;
			maxn=max(maxn,cy);
			//printf("1 x=%d l=%d r=%d cnt=%d\n",x,l,r,cnt);
		}
		else{
			//printf("2 x=%d l=%d r=%d cnt=%d\n",x,l,r,cnt);
			cnt-=(a[r]-a[l]);
			cy--;
			l++;
		}
	}
	cout<<maxn;
	return 0;
}
