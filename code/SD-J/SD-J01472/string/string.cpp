#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,i,ans=0;
    long long a,mid=0,len=0;
    char c;
    string s;
    cin>>n;
    for(i=1;i<=n;i++)
    {
    	cin>>a>>c;
    	s.append(a,c);
	}
	len=s.size();
	mid=len/2;
	for(i=0;i<mid;i++)
	{
		if(s[i]!=s[n-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}

