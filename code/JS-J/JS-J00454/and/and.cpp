#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],num[200];string b[200005];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1){cout<<a[n];}
    if(m==2){cout<<(a[n]&a[n-1]);}
    return 0;
}
