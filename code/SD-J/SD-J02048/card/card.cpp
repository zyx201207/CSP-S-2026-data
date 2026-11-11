#include<iostream>
#include<cstring>
#include<ctime>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<list>
#include<stack>
using namespace std;
int a[500010],st[500010],top;
int t[300010],last[300010];
bool f=1; 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		last[a[i]]=i;
		if(a[i]<a[i-1])    f=0;
	}
	if(f)
	{
		for(int i=1;i<=m;i++)    cout<<last[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++)//µÚ i ¾Ö 
	{
		top=0;
		for(int j=i;j<=n;j++)
		{
			st[++top]=a[j];
			for(int z=1;z<=top;z++)
			{
				if(st[z]==a[j])
				{
					top=z;
					break;
				}
			}
		}
		for(int j=1;j<=top;j++)
		{
//			cout<<st[j]<<" ";
			t[st[j]]++;
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++)    cout<<t[i]<<" ";
	return 0;
}

