#include<bits/stdc++.h>
using namespace std;
int a[1010];
int s;
int i;
int l=0,r;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}

    sort(a+1,a+1+n);

	if((a[1]+a[2]+m+a[3])%a[3]==0);
		{
		s+=(a[1]+a[2]+m+a[3])/a[3];
		}


    
cout<<s;
	return 0;
}