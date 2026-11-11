#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
const int N=5e+5+5;
int n,cnt,num[N];
long long w[N],m,co[N],cost[N];
map<long long,int> mp;

bool cmp(long long a,long long b){return a<b;}

void init(){
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
	sort(w+1,w+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(mp[w[i]]==0){mp[w[i]]=(++cnt);cost[cnt]=w[i];}
		num[mp[w[i]]]++;
	}
	for(int i=1;i<=cnt;i++) co[i]=num[i]*(cost[cnt]-cost[i]);
	for(int i=1;i<=cnt;i++) num[i]+=num[i-1];
	for(int i=cnt;i>=1;i--) co[i]+=co[i+1];
}

int finder(int x){
	int l=1,r=x,mid=((l+r)>>1),res=x,tmp=0;
	long long c;
	while (l<=r){
		c=co[mid]-co[x]-(num[x-1]-num[mid-1])*(cost[cnt]-cost[x]);
		if(c<=m){res=mid;r=mid-1;}
		else l=mid+1;
		mid=((l+r)>>1);
	}
	if(res==1) return num[x];
	c=co[res]-co[x]-(num[x-1]-num[res-1])*(cost[cnt]-cost[x]);
	tmp=(m-c)/(cost[x]-cost[res-1]);
	return num[x]-num[res-1]+tmp;
}

void calc(){
	int ans=0;
	for(int i=1;i<=cnt;i++) ans=max(ans,finder(i));
	printf("%d",ans);
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	init();
	calc();
	return 0;
}
