#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n,m;
    int a[100010],b[100010];
    int x=a[1];
    for(int i=2;i<=n;i++)
    {
    	cin>>a[i];
    	if(a[i]>x) x=a[i];
	}
	cout<<x;
    return 0;
}
