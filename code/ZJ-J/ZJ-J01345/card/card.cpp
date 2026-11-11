#include<bits/stdc++.h>
using namespace std;
vector <long long> a[600000];
long long n,m,k,da[2000000],kk[2000000],p[2000000],t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>kk[i];
		a[kk[i]].push_back(i);
		p[i]=a[kk[i]].size()-1;
		
	}
	for(int i=1;i<=n;i++)
	{
		k=i;
		//cout<<a[2].size()-1;
		//cout<<i<<endl;
		//cout<<999;
		while(1)
		{
		     da[kk[k]]++;
		     //cout<<k<<endl;
		     if(k>=n) break;
		     ///cout<<a[k].size()-1;
		    // cout<<9999;
			 t=p[k];
			if(a[kk[k]].size()-1==t)
			{
				k++;
			}
			else
			{
				k=a[kk[k]][a[kk[k]].size()-1]+1;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<da[i]<<" ";
	}
	
}
/*4 3 
1 2 1 3 1 2 3 1 2 3 1 2 3 2 3 2 1 2 3
1-3
3-4
4-5
5-6*/

