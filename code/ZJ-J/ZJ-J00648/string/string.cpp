#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long ans=0,n;
    cin >> n;
    int a[n+1];
    char s[n+1];
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i] >> s[i];
    }
    int j = n,x = 1,abc;
    while(x<j)
    {
        if(s[x] == s[j])
        {
        	abc = a[x];
            a[x] -= min(a[x],a[j]);
            a[j] -= min(a[j],abc);
            if(a[x]==0)
        	{
            	x++;
        	}
        	if(a[j]==0)
        	{
        	    j--;
        	}
        	continue;
        }
        if(s[x] != s[j])
        {
            ans += min(a[x],a[j]);
            a[x] -= min(a[x],a[j]);
            a[j] -= min(a[x],a[j]);
            if(a[x]==0)
        	{
       	     x++;
      	    }
        	if(a[j]==0)
        	{
            	j--;
        	}
        }
    }
    cout << ans;
    return 0;
}
