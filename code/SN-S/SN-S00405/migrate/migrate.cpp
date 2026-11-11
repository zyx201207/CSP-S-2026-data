#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e6+10,inf=2e18+7;
int n,x[N],d,pre[N],nxt[N];
int f[N],g[N];
int ql[N],qr[N];
int pl[N],pr[N];
void work(){
	int ans=0;
	int t=1;
	for(int i=1;i<=n;i++){
		while(t<=i&&x[i]-x[t]>d)++t;
		pre[i]=t;
	}
	t=n;
	for(int i=n;i>=1;i--){
		while(t>=i&&x[t]-x[i]>d)--t;
		nxt[i]=t;
	}
	for(int i=1;i<=n;i++)ql[i]=qr[i]=pl[i]=pr[i]=0;
	for(int i=1;i<=n;i++){
		int r=i;
		while(r+1<=n&&nxt[r+1]==nxt[i])++r;
		ql[nxt[i]]=i;
		qr[nxt[i]]=r;
		i=r;
	}
	for(int i=1;i<=n;i++){
		int r=i;
		while(r+1<=n&&pre[r+1]==pre[i])++r;
		pl[pre[i]]=i;
		pr[pre[i]]=r;
		i=r;
	}
	for(int i=1;i<=n;i++){
		f[i]=0;
		int ret=0;
		ret=max(ret,min(i-1,qr[i])-max(pre[i],ql[i])+1);
		f[i]+=ret;
		if(nxt[pre[i]]==i)f[i]+=f[pre[i]];
	}
	for(int i=n;i>=1;i--){
		g[i]=0;
		int ret=0;
		ret=max(ret,min(nxt[i],pr[i])-max(i+1,pl[i])+1);
		g[i]+=ret;
		if(pre[nxt[i]]==i)g[i]+=g[nxt[i]];
	}
	for(int i=2;i<n-1;i++){
		int t1=0,t2=0;
		int ret=0;
		ret=max(ret,min(nxt[i],pr[i])-max(i+1,pl[i])+1);
		t2+=ret;
		if(pre[nxt[i+1]]==i)t2+=g[nxt[i]];
		
		ret=0;
		ret=max(ret,min(i-1,qr[i+1])-max(pre[i+1],ql[i+1])+1);
		t1+=ret;
		if(nxt[pre[i]]==i+1)t1+=f[pre[i+1]];
		
		ans+=t1*t2;
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cid,T;cin>>cid>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		work();
	}
	return 0;
}
/*

0 1
10 22
0 7 14 21 28 35 42 49 56 63


0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000

0 1
6 3
0 1 2 3 4 7

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
