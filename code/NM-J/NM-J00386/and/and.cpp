#include<bits/stdc++.h>
using namespace std;
long long a[100000];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}	
	sort(a,a+n,cmp);	
	cout<<a[0] && a[1];
    return 0;
}
