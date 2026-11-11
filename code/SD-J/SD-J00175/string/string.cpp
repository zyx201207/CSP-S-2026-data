#include<bits/stdc++.h>
using namespace std;

struct two
{
	int n;
	char a;
};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	two ji[n];
	int l=0,r=n-1;
	long long ji1=0;
	for (int i=0;i<n;i++) cin>>ji[i].n>>ji[i].a;
	while (l<r)
	{
		if (ji[l].a!=ji[r].a)
		{
			int c=min(ji[l].n,ji[r].n);
			ji1+=c;
			ji[l].n-=c;
			ji[r].n-=c;
			if (ji[l].n==0) l++;
			if (ji[r].n==0) r--;
		}
		else
		{
			int c=min(ji[l].n,ji[r].n);
			ji[l].n-=c;
			ji[r].n-=c;
			if (ji[l].n==0) l++;
			if (ji[r].n==0) r--;
		}
	}
	cout<<ji1;
	return 0;
}
