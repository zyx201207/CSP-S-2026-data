#include<bits/stdc++.h>
using namespace std;
int a[5000000];
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
	int sum=1,vc=a[n];
	sort(a+1,a+1+n);
	for(int i=n-1;i<=0;i--)
	{
        if(a[i]==vc)
        {
            sum++;
            continue;
        }
        while(m<vc-a[i])
        {
            sum++;
        }
    }
    for(int i=0;i<=vc;i++)
    {

        vc+=sum;
    }
        cout<<sum;
	return 0;
}
