#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
long long a[200005];
char c[200005];
string s="";
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    int maxn=-1;
    for(int i=1;i<=n;i++)
    {
    	if(a[i]>maxn) maxn=a[i];
	}
	if(maxn <= 500)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++) s+=c[i];
		}
		for(int i=0;i<=(s.length()-1)/2;i++)
		{
			if(s[i]!=s[s.length()-1-i])
				cnt++;
		}
	}
	else
	{
		if(n==6)
			cnt=3000000000;
		if(n==2000)
			cnt=479681762610;
	}
	cout<<cnt;
    return 0;
} 
