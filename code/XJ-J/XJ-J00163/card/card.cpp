#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	queue<int> q;
	int cut[100005]={0};
	int ct[100005]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		cut[x]++;
		q.push(x);
	}
	
//	for(int i=1;i<=m;i++)
//	{
//		cout<<cut[i]<<" ";
//	}
	
	int j=1;
	while(!q.empty())
	{
		int z=q.front();
		q.pop();
		cut[z]--;
		if(cut[z]<=0)
		{
			ct[z]=j;
		}
		j++;
	}
//4 3
//1 2 1 3
	for(int i=1;i<=m;i++)
	{
		cout<<ct[i]<<" "; 
	 } 
	return 0;
}

