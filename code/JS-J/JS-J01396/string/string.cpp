#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long sum=0;
    long long a[214514];
    char c[214514];
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>c[i];
    }
    long long k1=0,k2=n-1;
    while(!(k1==k2||(k1>n/2&&k2<n/2)))
    {
        if(c[k1]!=c[k2])
        {
            long long kk=min(a[k1],a[k2]);
            a[k2]-=kk;
            a[k1]-=kk;
            sum+=kk;
            if(a[k1]==0)k1++;
            if(a[k2]==0)k2--;
        }
        else
        {
            if(a[k1]<a[k2])
            {
                a[k2]-=a[k1];
                k1++;
            }
            else if(a[k1]==a[k2])
            {
                k1++;
                k2--;
            }
            else
            {
                a[k1]-=a[k2];
                k2--;
            }
        }
        //cout<<k1<<' '<<k2<<endl;
    }
    cout<<sum;
    return 0;
}
