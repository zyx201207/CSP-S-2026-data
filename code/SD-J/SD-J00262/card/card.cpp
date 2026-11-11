#include <bits/stdc++.h> 
using namespace std;
const int N =2e5 + 5;
const int M =3e5 + 5;
map<int,int>mp;
int n,m,a[N],cnt[M],b[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		mp.clear();
		int l=0;
	    for(int j=1;j<=n;j++)
		{
		    if(mp.count(a[j])) l=mp[a[j]]-1;
		}
			b[++l]=a[j];
			mp[a[j]]=1;
		}	
		for(int j=1;j<=m;j++)
		{
		

			cnt[b[j]]++;
		}
    }
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';
	}
    return 0;
}
