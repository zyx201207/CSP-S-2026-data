#include <bits/stdc++.h>
using namespace std;//rp++;
typedef long long ll;//lose lose

const int N=500067;

ll a[N];ll need[N];
ll ans=-1;ll n,m,maxn=-1,minn=100000000000;bool cmp(int a,int b){return a>b;}

void init(){cin>>n>>m;for(int i=1;i<=n;i++){cin>>a[i];maxn=max(maxn,a[i]);minn=min(minn,a[i]);}sort(a+1,a+n+1,cmp);}

int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	init();
	
	for(int i=1;i<=n;i++)need[i]=a[i];
	for(int i=1;i<=n;i++)need[i]+=need[i-1];
	
	for(int line=maxn;line>=minn;line--){
		ll count=0,sum=0,left=1,i=1;
		while(line<a[i] &&i<=n){i++;}
		left=i;
		for(ll r=left;r<=n;r++){
			sum=(count-1)*line-need[r]+need[left+1];
			if(m>=sum){count++;}
			else break;
		}
		ans=max(ans,count);
	}
	cout<<ans;
}
