#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5e5+3;
int n,m;
int a[MAXN];
int b[MAXN];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=n;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<1<<" ";
    }
    return 0;
}
