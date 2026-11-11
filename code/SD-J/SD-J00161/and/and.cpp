#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
long long a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long maxx=0,x=a[1];
	for(int i=1;i<=n-m+1;i++)
	{
		int l=i,r=i+m-1;
		x=a[i];
        for(int j=l;j<=r;j++){
        	x=a[j]&x;
		}
		if(x>=maxx){
			maxx=x;
		}
	}
	cout<<maxx;
}
