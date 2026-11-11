/*
 * 是谁 衣白衫如初
 * 谁红裳如故
 * 谁人抚琴红莲赋
 * 又见谁一舞
 * 谁人贪恋谁踟蹰
 * 半池犹荣枯
 * 还在水榭畔 画楼处
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 800004
int n,ans;ll m,a[N],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ans=0;sum=0;
	for(int l=1,r=1;r<=n;++r){
		sum+=a[r];
		while(a[r]*(r-l+1)-sum>m)sum-=a[l],++l;
		ans=max(ans,r-l+1);
	}
	printf("%d\n",ans);
	return 0;
}
