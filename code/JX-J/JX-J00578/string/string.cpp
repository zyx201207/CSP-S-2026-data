#include<bits/stdc++.h>
using namespace std;
char c[499999900];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int m=1,k=0;
    for(int i=1;i<=n;i++)
    {
        long long a;
        char b;
        cin>>a;
        cin>>b;
        k+=a;
        for(int j=m;j<=a+m-1;j++)
        {
            c[j]=b;
        }
        m+=a;
    }
    int p=1,anss=0;
    for(int o=k;o>=1;o--)
    {
        if(c[o]!=c[p])
        {
            anss++;
        }
        p++;
    }
    cout<<anss/2;
    return 0;
}
