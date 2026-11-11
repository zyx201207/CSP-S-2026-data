#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long l,r;
	char c;
}a[200005];
int n,m;
long long ans,L;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char c;
		cin>>x>>c;
		if(c==a[m].c)
		{
			a[m].r+=x;
			L+=x;
			continue;
		}
		a[++m]={L+1,L+x,c};
		L+=x;
	}
	if(m==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1,j=m;i<j;)
	{
		int al=a[i].l,ar=a[i].r,bl=L+1-a[j].r,br=L+1-a[j].l;
		if(a[i].c!=a[j].c)
		{
			int cl=max(al,bl),cr=min(ar,br);
			ans+=cr-cl+1;
		}
        if(ar>br) j--;
        else if(ar==br)
        {
            i++;
            j--;
        }
		else i++;
	}
	cout<<ans;
	return 0;
}
