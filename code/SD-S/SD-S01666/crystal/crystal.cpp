#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],st[N][25],sum[N];
void build(){
	for(int i=1;i<=n;i++){
		st[i][0]=a[i];
	}
	for(int mk=1;mk<=23;mk++){
		for(int i=1;i+(1<<mk)-1<=n;i++){
			st[i][mk]=max(st[i][mk-1],st[i+(1<<mk-1)][mk-1]);
			//cout<<i<<' '<<mk<<' '<<st[i][mk]<<'\n';
		}
	}
}
ll query(ll L,ll R){
	ll k=R-L+1;
	k=log2(k);
	return max(st[L][k],st[R-(1<<k)+1][k]);
}
bool check(ll len){
	for(int i=1;i+len-1<=n;i++){
		ll maxx=query(i,i+len-1);
		ll ksum=sum[i+len-1]-sum[i-1]-maxx;
		//cout<<i<<' '<<maxx<<'\n';
		if(maxx*(len-1)-ksum<=m)	return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	build();
	//cout<<check(3);
	ll L=1,R=n;
	while(L<R){
		ll mid=(L+R+1)>>1;
		if(check(mid))	L=mid;
		else R=mid-1;
	}
	cout<<L;
	return 0;
} 
/*
5 5
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/
//±ð¹ÒÇóÄãÁË 
