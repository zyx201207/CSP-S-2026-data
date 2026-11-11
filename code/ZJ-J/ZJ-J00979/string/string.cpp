#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],cnt,x1,x2,flag;
string s,c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if (a[i]>pow(10,3)*2)
		{
			flag=1;
		}
    }
    if (flag==0)
    {
    	int i=1;
		for (int j=1;j<=a[i];j++)
		{
			s+=c[j];
			i++;
		}
	    for (int i=0;i<=s.length()/2;i++)
	    {
		    if (s[i]!=s[s.length()-1-i])
		    {
			    cnt++;
		    }
	    }
	    cout<<cnt;
	    return 0;
	}
    else
    {
	    for (int i=1;i<=n/2;i++)
	    {
		    if (a[i]==a[n-i+1]&&c[i]==c[n-i+1])
		    {
			    continue;
		    }
		    if (a[i]==a[n-i+1]&&c[i]!=c[n-i+1])
		    {
	     		cnt+=a[i];
	    	}
	    }
	    cout<<cnt;
	}
	return 0;
}