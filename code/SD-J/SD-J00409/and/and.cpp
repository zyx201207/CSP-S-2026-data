#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int w_n,w_m;
int w_a[MAXN];
int w_sum;
bool w_vis[MAXN];
int w_ans;
bool w_allm=1;
bool w_allj=1;
bool w_all4=1; 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>w_n>>w_m;
	for(int w_i=1;w_i<=w_n;w_i++)
	{
		cin>>w_a[w_i];
	}
	sort(w_a+1,w_a+w_n+1);
	for(int w_i=1;w_i<=w_n;w_i++)
	{
		if(w_a[w_i]!=w_i-1)
		{
			w_allj=0;
			break;
		}
	}
	bool w_b=0;
	for(int w_j=1;w_j<=15;w_j++)
	{
		if(w_n==pow(2,w_j)-1)
		{
			w_b=1;
			break;
		}
	}
	if(w_b==1&&w_allj==1)
	{
		int w_cnt=w_a[w_n];
		for(int w_i=w_n-1;w_i>=w_n-w_m+1;w_i--)
		{
			w_cnt&w_a[w_i];
			if(w_cnt==0)
			{
				break;
			}
		}
		cout<<w_cnt;
	}
	else if(w_allm==1)
	{
		cout<<w_a[w_n-w_m+1];
	}
	else if(w_n>=5e4+10)
	{
		w_sum=w_a[w_n];
		w_vis[w_n]=1;
		for(int w_i=2;w_i<=w_m;w_i++)
		{
			int w_j=1;
			while(w_vis[w_j]==1)
			{
				w_j++;
			}
			int w_bestsum=w_sum&w_j;
			int w_bid=w_j;
			w_j++;
			for(;w_j<=w_n;w_j++)
			{
				if(w_vis[w_j]==1)
				{
					continue;
				}
				else
				{
					if(w_bestsum<(w_sum&w_a[w_j]))
					{
						w_bestsum=w_sum&w_a[w_j];
						w_bid=w_j;
					}
				}
			}
			w_sum=w_bestsum;
			w_vis[w_bid]=1;
		}
		cout<<w_sum;
	}
	else
	{
		for(int w_i=1;w_i<=w_n;w_i++)
		{
			fill(w_vis+1,w_vis+w_n+1,0);
			w_sum=w_a[w_i];
			w_vis[w_i]=1;
			for(int w_j=2;w_j<=w_m;w_j++)
			{
				int w_k=1;
				while(w_vis[w_k]==1)
				{
					w_k++;
				}
				int w_bestsum=w_sum&w_k;
				int w_bid=w_k;
				w_k++;
				for(;w_k<=w_n;w_k++)
				{
					if(w_vis[w_k]==1)
					{
						continue;
					}
					else
					{
						if(w_bestsum<(w_sum&w_a[w_k]))
						{
							w_bestsum=w_sum&w_a[w_k];
							w_bid=w_k;
						}
					}
				}
				w_sum=w_bestsum;
				w_vis[w_bid]=1;
			}
			w_ans=max(w_ans,w_sum);
		}
		cout<<w_ans;
	}
	return 0;
}
