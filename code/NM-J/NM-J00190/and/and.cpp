#include <bits/stdc++.h>
using namespace std;
int maxn ;
int main()
{
    freopen("and.in","w",stdin);
    freopen("and.out","r",stdout);  
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x>maxn)
        {
            maxn=x;
        }
    }
    cout<<maxn;
    return 0;
}