#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m;
    int a[10005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	if(n<=5)
	{
		cout<<m<<a[1]<<n;
	}
	else if(n>=5&&n<=10)
	{
		cout<<n<<m<<a[1];
	}
	return 0;
}