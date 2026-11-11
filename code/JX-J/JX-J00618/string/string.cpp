#include<bits/stdc++.h>
using namespace std;
string s;
long long i,a;
string c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stddout);

    cin>>i;
    for(long long j=0;j<i;j++)
    {
        cin>>a>>c;
        for(long long t=0;t<a;t++)
        {
            s+=c;
        }
    }
    long long cnt=0,len=s.size()-1;
    for(long long j=0;j<s.size()/2;j++)
    {
        if(s[j]!=s[len-j])
        {
            cnt++;
        }
    }
    cout<<cnt;
return 0;
}
