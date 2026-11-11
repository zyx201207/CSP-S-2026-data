#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,b,ans=0,e=0;
    cin>>n>>k;
    int c=n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    while(n--)
    {
        e=0;
        for(int i=c-n-1;i<c;i++)
        {
            if(a[i]==k)
            {
                e=(e+1)%2;
            }
        }
        ans+=e;
    }
    cout<<ans;
    return 0;
}
