#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],xxx,mmm=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        xxx=a[i];
        for(int j=1;j<m;j++)
        {
            xxx=xxx&a[j+i];
        }
        mmm=max(mmm,xxx);
    }
    cout<<mmm;
    return 0;
}
