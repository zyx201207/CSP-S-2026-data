#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll n,m;
ll a[N],hand[N],zhuo[N];
ll ans[N];
int find(ll num1,ll x)
{
	for(int i=1;i<=num1;i++)
		if(zhuo[i]==x) 
			return i;
	return 0;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int nn=n;
	int ju=1;
	int num=1;
	int num1;
	while(nn--)
	{
		memset(hand,0,sizeof(hand));
		memset(zhuo,0,sizeof(zhuo));
		for(int i=ju;i<=n;i++)
			hand[i]=a[i];
		for(int i=1;i<ju;i++)
			zhuo[i]=a[i];
		num=n-ju;
		num1=ju;
		for(int i=1;i<=num;i++)
		{
			if(find(num1,hand[i])!=0)
			{
				for(int i=find(num1,hand[i]);i<=num1;i++)
					zhuo[i]=0;
				num1=find(num1,hand[i]);
				zhuo[num1]=hand[i];
				num1++;
			}
			else
			{
				zhuo[num1]=hand[i];
				num1++;
			}
		}
		for(int i=1;i<=m;i++)
			ans[zhuo[i]]++;	
		ju++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;	
} 
