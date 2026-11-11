#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll A[200005];
struct node{
	ll l,r;
	char c;
};
node s[200005];
node d[200005];
ll mid;
int L,R;
ll ln,rn;
ll ans;
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&A[i],&s[i].c);
		A[i]+=A[i-1];
	}
	mid=A[n]/2;
	L=1,R=n;
	ln=1,rn=A[n];
	while(ln<=mid){
		if(ln>A[L]) L++;
		if(rn<A[R-1]+1) R--;
		if(s[L].c!=s[R].c) ans++;
		ln++;
		rn--;
	}
	printf("%lld",ans);
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	return 0;
}