#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	ll arr[n+100]={};
	ll geshu[m+100]={};
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	int mm,s;
	for(int i=1;i<=n;i++)
	{
		int zhuo[500010]={};
		int jilu[m+10]={};
		s=1;
		for(int j=i;j<=n;j++)
		{
			mm=0;
			for(int k=1;k<s;k++)
			{
				if(zhuo[k]==arr[j])
				{
					mm=k;
					break;
				}
			}
			if(mm==0)
			{
				zhuo[s]=arr[j];
				s++;
			}else
			{
				for(int k=mm;k<s;k++)
				{
					if(jilu[zhuo[k]]!=0)
					geshu[zhuo[k]]-=1;
					jilu[zhuo[k]]=0;
					zhuo[k]=0;
				}
				zhuo[mm]=arr[j];
				s=mm+1;
			}
			for(int k=1;k<s;k++)
			{
				if(jilu[zhuo[k]]==0)
				geshu[zhuo[k]]+=1;
				jilu[zhuo[k]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<geshu[i]<<" ";
	}
	return 0;
}

