#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll sum;
struct A{
    ll nm;
    char c;
}a[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].nm>>a[i].c;
    }
    int l=1,r=n;
    while(l<r)
    {
        ll tp=min(a[l].nm,a[r].nm);
        a[l].nm-=tp;
        a[r].nm-=tp;
        if(a[l].c!=a[r].c)
            sum+=tp;
        if(a[l].nm==0)
            l++;
        if(a[r].nm==0)
            r--;
    }
    cout<<sum;
    return 0;
}
