#include<bits/stdc++.h>
using namespace std;
struct str{
	int x;
	int id;
};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m=0,crdout[10000]={0},x=0;

	str num[10000];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>crdout[i];
	}
	for(int i=1;i<=m;i++)
	{
		int crdin[10000]={0};
		crdin[i-1]=crdout[i-1];
		for(int j=0;j<i;j++)
		{
			if(crdin[j]==crdout[i-1])
			{
				num[i-1].id=crdin[j];
				num[i-1].x++;
				break;
			}
		}

	}
	for(int j=0;j<m;j++)
	{
		cout<<num[j].x<<" ";
	}
	return 0;
}
