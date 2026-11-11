#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll m,n;
ll a[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    sort(a,a+m);
    cout<<a[(m+1)/2];
    return 0;
}
