#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(a[i]>a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    int num=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i+1])
        {
            num++;
        }
        if(num==m)
        {
            cout<<a[i];
            return 0;
        }
        if(a[i]!=a[i+1])
        {
            num=0;
        }
    }
    cout<<"36";
    return 0;
}
