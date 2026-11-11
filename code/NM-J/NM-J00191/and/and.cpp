#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a[200005],mx=0;
    cin>>n>>m;
    if(m==1)
    {
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(a[i]&a[j]>mx)
            {
                mx=a[i]&a[j];
            }
        }
    }
    cout<<mx;
    return 0;
}
