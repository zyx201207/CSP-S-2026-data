#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int num,a[100005],sum=0,g=0,k=1;
    char b[100005],c[100005];
    cin>>num;
    for(int i=1;i<=num;i++)
    {
        cin>>a[i];
        cin>>b[i];
    }
    for(int i=1;i<=num;i++)
    {
        sum+=a[i];
    }
    for(int i=1;i<=num;i++)
    {
        for(int j=a[i];j>=1;j--)
        {
            c[k]=b[i];
            k+=1;
        }
    }
    if(sum%2==0)
    {
        for(int i=1,j=sum;i<=sum/2,j>sum/2;i++,j--)
        {
            if(c[j]!=c[i])
                g+=1;
        }
    }
    else
    {
        for(int i=1,j=sum;i<=sum/2,j>sum/2+1;i++,j--)
        {
            if(c[j]!=c[i])
                g+=1;
        }
    }
    cout<<g<<endl;
    return 0;
}
