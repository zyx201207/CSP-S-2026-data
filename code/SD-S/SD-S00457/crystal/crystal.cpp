#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<set>
#include<map>
#define r read()
using namespace std;
long long read(){
	long long x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch&15);ch=getchar();}
	return x*f;
}
const int N=5e5+5;
int n,b[N],cnt[N],ans,tmp,ls,lr;
long long a[N],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=r,m=r;
	for(int i=1;i<=n;i++){
		a[i]=r;
	}
	sort(a+1,a+n+1);
//	int len=unique(a+1,a+n+1)-a-1;
//	for(int i=1;i<=n;i++){
//		int x=lower_bound(a+1,a+n+1,a[i])-a;
//		++cnt[x];
//	}
	ls=lr=1,ans=tmp=1;
	for(int i=2;i<=n;i++){
		m-=1ll*(lr-ls+1)*(a[i]-a[i-1]);
		while(m<0)m+=a[i]-a[ls],++ls;
		lr=i;
		tmp=lr-ls+1;
		ans=max(ans,tmp);
	}
	printf("%d\n",ans);
	return 0;
}
