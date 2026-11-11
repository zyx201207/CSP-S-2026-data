#include<bits/stdc++.h>
using namespace std;
void file(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}
#define ll long long
#define N 2000005
ll x[N],d;int c,T,n;
void solve_A(){
	ll diff=x[2]-x[1];
	if(diff>=d){puts("0");return;}
	ll k=d/diff;
	printf("%lld\n",max(0LL,n-(2*k-1)));
}
ll f[N],g[N];
void solve_bf(){
	ll res=0;
	for(int l=1;l<=n;l++){
		f[l]=0;
		g[l]=1;
		for(int i=l+1;i<=n;i++)f[i]=n+1,g[i]=0;
		int j=l;
		for(int i=l+1;i<=n;i++){
			while(x[i]-x[j]>d)++j;
			for(int k=j;k<i;k++)f[i]=min(f[i],f[j]+1);
			if(f[i]>n)continue;
			int cnt=0;
			for(int k=j;k<i;k++)
				if(f[k]==f[i]-1)g[i]+=g[k];
			if(g[i]==2)++res;
		}
	}
	printf("%lld\n",res);
}
int main(){
	file();
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		if(c==11||c==12)solve_A();
		else solve_bf();
	}
	return 0;
}
