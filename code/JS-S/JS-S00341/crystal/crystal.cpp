#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m;
int a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int ans=1,g=a[2]-a[1],s=0;
    for(int i=1; ;i++)
    {
        s+=g*i;
        ans++;
        if(s==m) break;
        if(s>m)
        {
            ans--;
            break;
        }
    }
    cout<<ans;
    return 0;
}
