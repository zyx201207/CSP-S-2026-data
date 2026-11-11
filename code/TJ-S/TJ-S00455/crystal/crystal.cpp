#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int maxn=5e5+7;
int a[maxn],pre[maxn],ans,num;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) 
	{
		pre[i-1]=a[i]-a[i-1];
	}
	for(int i=1;i<n;i++)
	{
		if(ans+pre[i]*i>m) 
		{
			break;
		}
		ans=ans+pre[i]*i;
		num++;
	}
	cout << ++num;
	return 0;
}
//Ò»°ÝÍ¼Áé ×£ÎÒÖÁÉÙ85pts
//¶þ°ÝÍ¼Áé ×£ÎÒ-SÒ»µÈ½±°¡°¡°¡
//Èý°ÝÍ¼Áé ×£ÎÒ²Á±ßÒ»µÈ½±°¡°¡°¡
//Í¼Áé±£ÓÓ 
//Í¼Áé±£ÓÓ 
//Í¼Áé±£ÓÓ 
//Í¼Áé±£ÓÓ 
//Í¼Áé±£ÓÓ
//Í¼Áé±£ÓÓ 
//Í¼Áé±£ÓÓ 
//Í¼Áé±£ÓÓ 
//Í¼Áé±£ÓÓ 
//Í¼Áé±£ÓÓ 
//Í¼Áé±£ÓÓ 
