#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 2e6 + 7;
int c,T,n;
ll d,a[MAXN];
bool isprime(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true;
}
void solve1(){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	ll nmd=a[2]-a[1];
	ll sb=d/nmd;
	ll ans=0;
	for(int i=1;i<=n-sb-1;i++){
		int len=(n-i+1);
		for(int i=1;i<=len;i++){
			
			for(int j=2;j<=sb;j++){
				if(i%j==0){
					bo=false;
					break;
				}
			}
			if(bo) ans++;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		solve1();
	}
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/