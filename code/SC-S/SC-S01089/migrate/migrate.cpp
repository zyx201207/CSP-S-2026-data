#include<bits/stdc++.h>
typedef long long ll;
void read(int &x){
	x=0;
	int sg=1;
	char now;
	while(true){
		now=getchar();
		if(now=='-')
			sg=-1;
		if(now>='0'&&now<='9')
			break;
	}
	while(now>='0'&&now<='9'){
		x=x*10+(now-'0');
		now=getchar();
	}
	x*=sg;
}
void read(ll &x){
	x=0;
	int sg=1;
	char now;
	while(true){
		now=getchar();
		if(now=='-')
			sg=-1;
		if(now>='0'&&now<='9')
			break;
	}
	while(now>='0'&&now<='9'){
		x=x*10+(now-'0');
		now=getchar();
	}
	x*=sg;
}
using namespace std;
const int N=2e6+5;
int n,nxt[N];
ll a[N],d,wp[N],wn[N];
void init(){
	read(n),read(d);
	for(int i=1;i<=n;i++)
		read(a[i]),wn[i]=1,wp[i]=0;
	for(int l=1,r=1;l<=n;l++){
		while(r<n&&a[r+1]-a[l]<=d)
			++r;
		nxt[l]=r;
	}
}
void work(){
	ll ans=0;
	for(int i=n-1;i>=1;i--)
		if(nxt[i]>i)
			wn[i]+=nxt[i]-nxt[i-1]-1+(nxt[i]>nxt[i-1]?wn[nxt[i]]:1);
	for(int i=n-3;i>=1;i--){
		int nxti=nxt[i];
		if(nxti==i)
			continue;
		if(nxti==i+1){
			wp[i]=wp[i+1];
			continue;
		}
		int l=max(nxti+1,nxti-2>i?nxt[nxti-2]+1:0),r=nxt[nxti-1];
		if(l<=r){
//			wp[i]+=r-l+1+(r==nxt[nxti])*(wn[r]-1);
			if(r==nxt[nxti])
				wp[i]=r-l+wn[r];
			else
				wp[i]=r-l+1+wp[nxti];
		}
		else
			wp[i]=wp[nxti];
//		printf("%d %d %d %lld\n",i,l,r,wp[i]);
	}
	for(int i=1;i<=n;i++)
		ans+=wp[i];
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	read(c),read(t);
	if(c==11||c==12){
		while(t--){
			read(n),read(d);
			for(int i=1;i<=n;i++)
				read(a[i]),wn[i]=1,wp[i]=0;
			ll dd=(d/(a[2]-a[1]))*2-1;
			if(dd<=1)
				printf("0\n");
			else
				printf("%lld\n",max(0ll,n-dd));
		}
		return 0;
	}
	while(t--){
		init();
		work();
	}
	return 0;
}
/*
0 1
9 3
1 2 3 4 5 6 7 8 9
*/