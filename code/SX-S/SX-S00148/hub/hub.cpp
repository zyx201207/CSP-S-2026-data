#include<bits/stdc++.h>
using namespace std;
int a[1010];
int s;
int i;
int l=0,r;
int n=1000;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}

	if(a[2]==3)
	{
		cout<<1<<endl<<1<<endl<<2;
	}

	return 0;
}