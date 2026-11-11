#include<bits/stdc++.h>
using namespace std;
struct node 
{
	int num;
	int prev=-1;
}card[5000050];
map<int,int> ma;
int cnt[500050]={0};
priority_queue<int,vector<int>,greater<int> > pq;
int n,m; 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>card[i].num;
		card[i].prev=ma[card[i].num];
		ma[card[i].num]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>n-i;j--)
		{
			while(card[j].prev>n-i) 
			{
				j=card[j].prev;
			}
			cnt[card[j].num]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
} 
