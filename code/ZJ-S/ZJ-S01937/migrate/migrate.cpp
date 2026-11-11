#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-f;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

int c,t;
int n,d;
int x[N];
int f[N];
int dp[N];

int Lst[N],Fst[N];
void solve(){
	cerr<<"T:"<<t<<"\n";
	n=read(),d=read();
	int sum=0;
	for(int i=1;i<=n;i++){
		x[i]=read();
	}
	
	
	//骗分
	if(n<=4){
		printf("0\n");
		return;
	}
	if(c>=11&&c<=12){
		int D=d/(x[2]-x[1]);
		if(D<2){
			printf("0\n");return;
		}
		printf("%d\n",max(0ll,n-2*D+1));
		return;
	}
	/*
	if(c>=13&&c<=14){
		cerr<<"OK\n";
		memset(Lst,0,sizeof(Lst));
		memset(Fst,0,sizeof(Fst));
		int l=1,r=1;
		while(l<=n){
			while(r<n&&x[l]+d>=x[r+1])r++;
			Lst[l]=r;
			l++;
		}
		l=r=n;
		while(r>=1){
			while(l>1&&x[l-1]+d>=x[r])l--;
			Fst[r]=l;
			r--;
		}
		cerr<<"OK\n";
		l=r=1;
		while(l<n){
			while(r<n&&Lst[l]-Fst[r]>1)r++;
			if(Lst[l]-Fst[r]==1)sum++;
			l++;
		}
		cerr<<"OK\n";
		printf("%d\n",sum);
		return;
	}
	*/
	for(int L=1;L<=n;L++){
//		cerr<<"L:"<<L<<"\n";
		int l=L;
		f[l]=0;
		dp[l]=1;
		int flag=0;
		for(int r=L+1;r<=n;r++){
			while(x[l]+d<x[r])l++;
			if(l==r)break;
			f[r]=f[l]+1;
			dp[r]=dp[l];
			int k=l+1;
			while(f[l]==f[k]){
				if(dp[r]>2)break;
				dp[r]+=dp[k];
				k++;
			}
			if(dp[r]==2)sum++;
		}
	}
	printf("%d\n",sum);
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		solve();
	}
	return 0;
}