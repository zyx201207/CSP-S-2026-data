#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ma=-100;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(a[i]&a[j]>=ma)
            {
                ma=a[i]&a[j];
            }
        }
    }
    cout<<ma<<endl;
    return 0;
}
