#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxn=-1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>maxn)
            maxn=a[i];
    }
    if(maxn<4)
    {
        sort(a,a+n);
        int a1,a2,a3;
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)
            {
                a1++;
            }
            if(a[i]==2)
            {
                a2++;
            }
            if(a[i]==3)
            {
                a3++;
            }
        }
        if(a3>=m)
        {
            cout<<3;
            return 0;
        }
        if(a3+a2>=m)
        {
            cout<<2;
            return 0;
        }
        if(a3+a1>=m)
        {
            cout<<1;
            return 0;
        }
    }
    return 0;
}
