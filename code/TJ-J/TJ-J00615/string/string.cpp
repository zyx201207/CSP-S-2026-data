#include <bits/stdc++.h>
#define Trick 8
#define Treat 8
#define int long long
using namespace std;
const int N=2e5;
int ans;
int l,r;
struct S{
	int n;
	char c;
	void input(){
		scanf("%lld %c",&n,&c);
	}
	void die1(S &t){//l
		int lose=min(n,t.n);
		n-=lose,t.n-=lose;
		if(n==0){
			l++;
		}
		if(t.n==0)
			r--;
		if(t.c!=c)
			ans+=lose;
	}
	void output(){
		printf("%lld %c\n",n,c);
	}
}st[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%lld",&n);
	r=n-1;
	for(int i=0;i<n;i++){
		st[i].input();
	}
	while(l<r){
		st[l].die1(st[r]);
	}
	printf("%lld",ans);
	return Trick^Treat;
}
