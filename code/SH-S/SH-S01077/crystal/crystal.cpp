#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll N,M,qzh[500005],a[500005],Ans;
ll Cal(ll Lef,ll Rig)
{
	return (Rig-Lef+1)*a[Rig]-(qzh[Rig]-qzh[Lef-1]); 
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	scanf("%lld%lld",&N,&M);
	for(int i=1;i<=N;i++) scanf("%lld",&a[i]);
	sort(a+1,a+N+1);
	for(int i=1;i<=N;i++) qzh[i]=qzh[i-1]+a[i];
	//选定第i个水晶作为到达的目标
	Ans=1;
	for(int i=2;i<=N;i++)
	{
		ll L=1,R=i;
		while(L<R)
		{
			ll mid=L+R>>1;//mid~i为改变的水晶 
			if(Cal(mid,i)<=M) R=mid;
			else L=mid+1;
		}
		//L~i 为最大 
		Ans=max(Ans,i-L+1);
	 } 
	printf("%lld",Ans);
	return 0; 
 } 
