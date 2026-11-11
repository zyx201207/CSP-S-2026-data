#include <bits/stdc++.h>
using namespace std;
int s[500010];
int t[500010];
int n;
long long m;
int ret;
int main(){
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        cin>>s[i];
    }
    sort(s+1,s+n+1);
    for (int i=1; i<=n; i++)
    {
        t[i]=s[i]-s[i-1]+t[i-1];
    }
    int x=1,y=1;
    while (x<=y && y<=n)
    {
		long long ret=t[y]-t[x-1]-(s[y]-s[x-1])*(x-1);
		if (ret<m)
		{
			y++;
		}
		else
		{
			x++;
		}
		if (ret>y-x+1)
		{
			ret=y-x+1;
		}
	}
	cout<<ret;
    return 0;
}
