#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
long long sum[N],p[N],d,ans2,ans3;
int nxt[N],n;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cid,T;scanf("%d %d",&cid,&T);
	while(T--){
		//zero();
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&p[i]);
		for(int l=n,r=n;l>=1;l--){
			while(p[r]-p[l]>d) r--;
			nxt[l]=r;
		}
		ans2=ans3=0;
		for(int i=n;i>=1;i--)
			sum[i]=sum[nxt[i]]+max(0,nxt[nxt[i]-1]-nxt[i]);
		for(int i=1;i<=n;i++) ans2+=sum[i];
		for(int i=n;i>=1;i--)
			sum[i]=sum[nxt[i]]+max(0,nxt[nxt[i]-2]-nxt[i]);
		for(int i=1;i<=n;i++) ans3+=sum[i];
		printf("%lld\n",ans2-ans3);
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/