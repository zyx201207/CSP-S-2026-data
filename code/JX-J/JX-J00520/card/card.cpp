#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],n,cnt[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
    int s=0;
    for(int i=1;i<=n;i++)
    {
        s+=cnt[a[i]];
        cout<<s<<" ";
    }
    return 0;
}