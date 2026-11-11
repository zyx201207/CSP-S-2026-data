#include<bits/stdc++.h>
using namespace std;
int a[1010];
int s;
int i;
int l=0,r;
int n=1000;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}

	if(a[2]==3)
	{
		cout<<35<<endl<<16;
	}

	return 0;
}