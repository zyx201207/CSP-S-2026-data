#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("and.in","r",stdin);
    freopen ("and.out","w",stdout);
    int n,m[n],max=0,a[n];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>m[i];
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            a[i]=m[i]^m[j];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
            max=a[i];

    }
    cout<<max;
    return 0;
}
