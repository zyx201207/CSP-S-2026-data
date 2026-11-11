#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
queue<long long>cards;
long long s[MAXN];
long long nums[MAXN];
long long visit[MAXN]={};
int main()
{
	freopen("cards.in","r",stdin);
	freopen("cards.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		cards.push(a);
	}
	for(int i=1;i<=n;i++)
	{
		queue<long long>c=cards;
		fill(visit,visit+MAXN,0);
		long long cs=c.size();
		for(int j=1;j<=cs;j++)
		{
			s[j]=c.front();
			if(visit[c.front()]!=0){
				for(int k=0;k<j-1;k++) 
				{
					s[visit[c.front()]+k]=0;
				}
			}
			visit[c.front()]=j;
			c.pop();
		}
		for(int j=1;j<=cs;j++)
		{
			nums[s[j]]++;
		}
		cards.pop();
	}
	for(int i=1;i<=m;i++)
	{
		cout<<nums[i]<<" ";
		
	}
	return 0;
}