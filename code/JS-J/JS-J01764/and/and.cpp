
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans=0;
    int a[10010],cnt[100010];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=n-1;i>0;i--)
        ans+=i;
    int cnt1=ans;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            cnt[ans]=a[i]&a[j];
            ans--;
        }
    }
    int max=cnt[1];
    for(int i=2;i<=cnt1;i++)
    {
        if(cnt[i]>max)
            max=cnt[i];
    }
    cout<<max;
    return 0;
}
