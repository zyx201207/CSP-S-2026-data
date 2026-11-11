#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct node{
	long long nxt,to;
}e[N];
long long c,t,n,k,cnt,h[N],sum[6];
void lsqxxing(int u,int v){
	e[++cnt].to=v;
	e[cnt].nxt=h[u];
	h[u]=cnt;
}
bool check(int x){
	for(int i=1;i<=x;i++)
		if(sum[i]==4)
			return 1;
	return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		int u,v;
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			lsqxxing(u,v);
			if(n<=5){
				sum[u]++;
				sum[v]++;
			}
		}
		if(n<=5&&k>=2)
			cout<<1<<'\n';
		else if(n<=5){
			if(check(n))
				cout<<1<<'\n';
			else
				cout<<2<<'\n';
		} 
	}
	return 0;
}
