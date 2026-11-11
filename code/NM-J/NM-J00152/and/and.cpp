#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,kk;
const int maxn=2*1e5+5;
const long long INF=(2<<31)-1;
long long a[maxn],b[maxn];
bool cmp(const int &x,const int &y)
{
	return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ans=0;
	for(int i=1;i<=n-m+1;i++)
	{
		kk=a[i];
		for(int j=i+1;j<=m+i-1;j++)
		{
			kk=kk&a[j];
		}
		ans=max(ans,kk);
	}
	cout<<ans;
		fclose(stdin);
	fclose(stdout);
    return 0;
}

