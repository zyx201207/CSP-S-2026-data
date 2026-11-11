#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rd read()
int read(ll u=0,bool f=false,char c=getchar()){
	for(;!isdigit(c);c=getchar()) f|=(c=='-');
	for(;isdigit(c);c=getchar()) u=(u<<1)+(u<<3)+(c^'0');
	return f?-u:u;
}void wt(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wt(x/10);
	putchar((x%10)^'0');
}void wt(ll x,char c){wt(x);putchar(c);}
const int N=2e6+10;
int n,r[N],cnt[N][3];ll d,x[N],ans;
void work(){
	n=rd,d=rd;r[n]=n;cnt[n][0]=cnt[n][1]=cnt[n][2]=0;ans=0;
	for(int i=1;i<=n;i++) x[i]=rd;
	for(int lst=n,i=n-1;i>=1;i--){
		while(x[lst]-x[i]>d) lst--;r[i]=lst;
		int r0=lst,r1=r[r0],r2=(r0-1<=i?r0:r[r0-1]),
			r3=(r0-2<=i?r0:r[r0-2]);
		int nc0=r0-i+r1-r2,nc1=r2-r3,nc2=0,
			c0=cnt[r0][0],c1=cnt[r0][1],c2=cnt[r0][2];
		if(r3!=r1){
			if(r2==r1) nc1+=c0-(r1-r0);
			else if(r2+1==r1) nc0+=c0-(r1-r0),nc2+=c2;
			else nc0+=c0-(r1-r0),nc2+=c1+c2;
		}cnt[i][0]=nc0,cnt[i][1]=nc1,cnt[i][2]=nc2;
		ans+=nc1+nc2;
	}wt(ans,'\n');
}
main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=rd,T=rd;
	while(T--) work();
	return 0;
}/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
