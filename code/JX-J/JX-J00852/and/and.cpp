#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,c=0;
    cin>>n>>m;
    int a[100005];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(a[j]>a[i])
            {
                c=a[j];
                a[j]=a[i];
                a[i]=c;
            }
        }
    }
    cout<<a[m-1];
    return 0;
}
