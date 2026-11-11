#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    next_permutation(a+1,a+1+n);
    for(int i=1;i<=m;i++)
        cout<<a[i];
    return 0;
}
