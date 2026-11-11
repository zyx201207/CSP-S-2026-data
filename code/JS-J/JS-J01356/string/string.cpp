#include <bits/stdc++.h>
using namespace std;
int a[200001];
char c[200001],b[200001];
int main()
{
    freopen("string.in","w",stdin);
    freopen("string.out","r",stdout);
    int n,sum=0,g=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        sum+=a[i];
        for(int j=0;j<=a[i];j++)
        {
            b[++j]+=c[i];
        }
    }
    for(int i=0;i<=sum-1;i++)
    {
        for(int j=sum-1;j>=0;j--)
        {
            if(b[i]!=b[j])
            {
                g++;
            }
        }
    }
    cout<<g;
    return 0;
}
