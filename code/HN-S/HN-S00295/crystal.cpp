#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[500010];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1,j=1,sum=0;i<=n;i++)
    {
        while(sum>m)
            sum-=a[i]-a[j],j++;
        ans=max(ans,i-j+1),sum+=(i-j+1)*(a[i+1]-a[i]);
    }
    cout<<ans;
    return 0;
}
/*
g++ crystal.cpp -o crystal -std=c++14 -O2 -Wall
*/
/*
//freopen
诱捕器
luoguuid:984809
wzx终究退役了，但我已经不知道写什么了
*/