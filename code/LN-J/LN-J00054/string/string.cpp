#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long sum=0;
    string s=" ";
    for(int i=1;i<=n;i++)
    {
        long long a;
        char c;
        cin>>a>>c;
        sum+=a;
        for(int j=1;j<=a;j++)
        {
            s+=c;
        }
    }
    string qa=" ";
    string ha=" ";
    for(int i=1;i<=sum/2;i++)
    {
        qa+=s[i];
    }
    for(int i=sum;i>=(sum-sum/2+1);i--)
    {
        ha+=s[i];
    }
    long long cnt=0;
    for(int i=1;i<=sum/2;i++)
    {
        if(qa[i]!=ha[i])cnt++;
    }
    cout<<cnt;
    return 0;
}
