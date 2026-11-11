#include<bits/stdc++.h>
using namespace std;
const int N=500010; 
int n,m,a[N];
bool b[N];
int ans[N];
int top=0;
struct ttt
{
	int val;
	int key;
}zhan[N];
int main()
{
	ifstream fin("card.in");
	ofstream fout("card.out");
	fin>>n>>m;
	for(int i=1;i<=n;i++)
		fin>>a[i];
	for(int j=1;j<=n;j++)
	{
		for(int i=j;i<=n;i++)
		{
			zhan[++top].key=i;
			if(b[a[i]])
			{
				while(zhan[top].val!=a[i])
				{
					b[zhan[top--].val]=false;
				}
			}
			if(!b[a[i]])
			{
				b[a[i]]=true;
				zhan[top].val=a[i];
			} 
		}
		for(int i=1;i<=n;i++)b[i]=false;
		for(int i=1;i<=top;i++)
			ans[zhan[i].val]++;
		top=0;
	}
	for(int i=1;i<=m;i++)
	fout<<ans[i]<<' ';
	return 0;
}
