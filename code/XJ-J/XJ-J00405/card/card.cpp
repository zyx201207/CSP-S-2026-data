#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;
int a[500010];
int cnt[300010];
int b[500010];
int lb;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	
	for(int i = 1;i<=n;i++)
	{
		lb = 0;
		for(int j = i;j<=n;j++)
		{
			bool findd = false;
			int k = 1;
			for(k;k<=lb;k++)
			{
				if(b[k]==a[j])
				{
					findd = true;
					break;
				}
			}
			if(findd==true)
			{
				lb = k;
				b[lb] = a[j];
//				cout<<11111;
			}
			else b[++lb] = a[j];
//			cout<<i<<" "<<j<<" "<<lb<<" "<<findd<<" "<<a[j]<<endl;
//			for(int k = 1;k<=lb;k++)
//			{
//				cout<<b[k]<<" ";
//			}
//			cout<<endl;
		}
		for(int j = 1;j<=lb;j++)
		{
//			cout<<b[j]<<" ";
			cnt[b[j]]++;
		}
//		cout<<endl;
	}
	for(int i = 1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	
	return 0;
}
