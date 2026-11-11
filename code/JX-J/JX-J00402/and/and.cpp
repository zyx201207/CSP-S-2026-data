#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool b[200005][31];
int main()
{
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        long long temp;
        cin>>temp;
        a[i]=temp;
        long long o=31;
        b[i][0]=1;
        while(temp)
        {
            b[i][o--]=(temp%2);
            temp>>=1;
        }
    }
    long long sum=(1024)*(1024)-1;
    cout<<sum;
    for(long long i=1;i<=31;i++)
    {
        long long q=0;
        for(long long j=1;j<=n;j++)
        {
            q+=(b[j][0]&&b[j][i]);
        }
        for(long long j=1;j<=n;j++)
        {
            cout<<b[j][i]<<" ";
        }
        cout<<q;
        cout<<endl;
        if(q>m)
        {
            for(long long j=1;j<=n;j++)
            {
                b[j][0]=b[j][i];
            }
        }
        if(q==m)
        {
            for(long long j=1;j<=n;j++)
            {
                b[j][0]=b[j][i];
            }
            for(long long j=1;j<=n;j++)
            {
                if(b[j][0])
                {
                    cout<<sum<<" ";
                    sum&=a[j];
                }
            }
            break;
        }
    }
    cout<<sum;
    return 0;
}
//3
//#001 01 1010101
//#000101001010
// 011 01 1101101
// 101 11 0111011
// 011 01 0101001
// xxv xv xv
