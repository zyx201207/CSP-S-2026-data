#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[300005];
int main()
{
	int n,m;cin>>n>>m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=0;i<n;i++)	cin>>a[i];
	for(int i=0;i<n;i++)
	{
		int v[500005];
		int sizec=0;
		for(int j=i;j<n;j++)
		{
			int fl=-1;
			for(int k=0;k<sizec;k++)
			{
				if(a[j]==v[k])
					fl=v[k];
				break;
			}
			if(fl==-1){v[sizec]=a[j];sizec++;}
			else{
				for(int i=sizec-1;i>fl;i--)
					v[i]=0;
				sizec=fl;
			}
		}
		for(int j=0;j<=sizec;j++)
		{
			b[v[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
