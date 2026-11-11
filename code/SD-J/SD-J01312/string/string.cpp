#include<bits/stdc++.h>
using namespace std;
long long n,ans;
char c;
struct node
{
	char c;
	int q;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].q>>a[i].c;
	int ka=1,kb=n;
	while(ka<=kb)
	{
		if(a[ka].q>a[kb].q)
		{
			if(a[ka].c!=a[kb].c)
				ans+=a[kb].q;
			a[ka].q-=a[kb].q;
			a[kb].q=0;
			kb--;
		}
		else
		{
			if(a[ka].c!=a[kb].c)
				ans+=a[ka].q;
			a[kb].q-=a[ka].q;
			a[ka].q=0;
			ka++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
