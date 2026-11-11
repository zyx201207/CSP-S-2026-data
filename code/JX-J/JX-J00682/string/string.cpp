#include<bits/stdc++.h>
using namespace std;
long long n,cnt,sum;
long long a;
char c;
char s[2147471522];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--)
    {
        cin>>a>>c;
        for(long long i=cnt;i<cnt+a;i++)
        {
            s[i]=c;
        }
        cnt+=a;
    }
    for(long long i=ceil(cnt/2.0);i<cnt;i++)
    {
        if(s[i]!=s[cnt-i-1])
        {
            sum++;
        }
        //cout<<i<<" "<<cnt-i-1<<" ";
    }
    cout<<sum;
    return 0;
}
