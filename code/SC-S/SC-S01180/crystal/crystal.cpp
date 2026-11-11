#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+7;
long long n,m,a[N],c[N<<1],st[N][20];

long long lowbit(long long x){return x&(-x);}
void add(long long idx,long long num){
	for(long long i=idx;i<=n;i+=lowbit(i)) c[i]+=num;
}
long long querys(long long idx){
	long long ret=0;
	for(long long i=idx;i>=1;i-=lowbit(i)) ret+=c[i];
	return ret;
}

void Init(long long to){
	long long lg=log2(to);
	for(long long i=1;i<=lg;i++){
		long long ar=n-(1<<i)+1;
		for(long long j=0;j<=ar;j++){
			st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
}

long long querym(long long l,long long r){
	long long lg=log2(r-l+1);
	return max(st[l][lg],st[r-(1<<lg)+1][lg]);
}

bool check(long long len){
	long long cost=9e18;
	for(long long r=len;r<=n;r++){
		long long l=r-len+1;
		long long sum=querys(r)-querys(l-1);
		long long maxn=querym(l,r);
		cost=min(cost,maxn*len-sum);
	}
	return (m>=cost);
}

void solve(){
	cin>>n>>m;
	long long l=1,r=n+1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		st[i][0]=a[i];
		add(i,st[i][0]);
	}
	Init(n);
	while(l<r){
		long long mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	cout<<l-1<<'\n';
	return;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}