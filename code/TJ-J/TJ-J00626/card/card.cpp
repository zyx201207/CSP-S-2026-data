#include<bits/stdc++.h> 
using namespace std;
long long m,n,a[200005],cnt[100000];
map<int,int> mp;
int main()
{
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	while(n--)
	{
		for(int i=1;i<=n;i++)
        {
    	    if(cnt[a[i]]==0) cnt[a[i]]++;
    	    else cnt[200005]={};
	    }
	    for(int i=1;i<=n;i++)
	    {
	        if(cnt[a[i]]==1) mp[a[i]]++;
    	} 
    }
	for(int i=1;i<=m;i++) cout<<mp[i]; 
	return 0;
} 
