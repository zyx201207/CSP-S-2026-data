#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
const int MAXM=3e5+10;
int w_n,w_m;
int w_a[MAXN];
bool w_vis[MAXN];
int w_ans[MAXM];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>w_n>>w_m;
	for(int w_i=1;w_i<=w_n;w_i++)
	{
		cin>>w_a[w_i]; 
	}
	for(int w_i=1;w_i<=w_n;w_i++)
	{
		fill(w_vis+w_i,w_vis+w_n+1,1);
		for(int w_j=w_i;w_j<=w_n;w_j++)
		{
			for(int w_k=w_j+1;w_k<=w_n;w_k++)
			{
				if(w_a[w_j]==w_a[w_k])
				{
					fill(w_vis+w_j,w_vis+w_k,0);
					w_j=w_k-1;
					break; 
				}
			}
		}
		for(int w_j=w_i;w_j<=w_n;w_j++)
		{
			if(w_vis[w_j]==1)
			{
				w_ans[w_a[w_j]]++;
			}
		}
	}
	for(int w_i=1;w_i<=w_m;w_i++)
	{
		cout<<w_ans[w_i]<<' ';
	}
	return 0;
}
