#include<bits/stdc++.h>
using namespace std;
struct node{
	long long al;
	char c;
}a[200010];
int n;
long long ans;
int main()
{
 	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].al;
		cin>>a[i].c;
	}
	int i=1,j=n;
	while(i<j)
	{
		long long mins=min(a[i].al,a[j].al);
		if(a[i].c!=a[j].c)
		{
			ans+=mins;
		}
		a[i].al-=mins;
		a[j].al-=mins;
		if(a[i].al==0) i++;
		if(a[j].al==0) j--;
	}
	cout<<ans;
    return 0;
}
