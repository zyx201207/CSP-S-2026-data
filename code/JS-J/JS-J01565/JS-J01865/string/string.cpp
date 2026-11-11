#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long a[N];
char p[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long ans=0;
    string s="";
    long long n;
    long long ac=0;
    cin>>n;
    for(long long i=1;i<=n;++i)
    {
        cin>>a[i]>>p[i];
        ans+=a[i];
    }
    for(long long i=1;i<=n;++i)
    {
        for(long long j=1;j<=a[i];++j)
        {
            s=s+p[i];
        }
    }
    string s1,s2,s3="";
    s1=s.substr(0,s.size()/2);
    if(s.size()%2==1)
    {
        s2=s.substr(s.size()/2+1,n);
    }
    else
    {
        s2=s.substr(s.size()/2,n);
    }
    for(long long i=s2.size()-1;i>=0;--i)
    {
		s3=s3+s2[i];
	}
    for(long long i=0;i<=(ans/2)-1;++i)
    {
        if(s1[i]!=s3[i])
        {
            ac++;
        }
    }
    cout<<ac;
    return 0;
}
