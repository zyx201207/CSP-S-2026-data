#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sin signed
#define endl "\n"
int n,m;
int t[1000010];
int a[1000010];
int ans[1000010];
int tt[1000010];
void js(int k)
{
	for(int i=1;i<=m;i++)
	    t[i]=0;
	for(int i=1;i<=n;i++)
		tt[i]=0;
	int tot=0;
	for(int i=k;i<=n;i++)
	{
		if(t[a[i]]==0)
			t[a[i]]=i;
		else
		{
			if(tt[t[a[i]]]==0)
			    for(int j=t[a[i]];j<i;j++)
			    	tt[j]=1;
			t[a[i]]=i;
		}
	}
	for(int i=k;i<=n;i++)
	{
		if(tt[i]==0)
			ans[a[i]]++;
	}
}
void js1()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		    ans[a[i-1]]=i-1;
	}
	ans[m]=n;
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
}
sin main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin>>n>>m;
    int flag=1;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	if(a[i-1]>a[i]) flag=0;
	}
    if(flag)
    {
    	js1();
    	return 0;
	}
	for(int i=1;i<=n;i++)
		js(i);
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
