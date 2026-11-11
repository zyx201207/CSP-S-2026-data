#include <bits/stdc++.h>
using namespace std;
long long a,k;
char b[1000002555];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a;
    long long ans=0,anss=0;
    for(long long i=0; i<=a-1; i++)
    {
        long long c;
        char d;
        cin>>c>>d;

        for(long long j=1; j<=c; j++)
        {
            b[j+k]=d;
            ans++;

        }
        k=ans;
    }



    for(long long i=1; i<=ans/2; i++)
    {

        if(b[i]!=b[ans-i+1])
        {
            anss++;

        }

    }

    cout<<anss;
    return 0;
}
