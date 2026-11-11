#include<bits/stdc++.h>
using namespace std;
long long a[200005],ans;
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int k=0;
    if(n==m){
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if((a[i]&a[j])>k&&i!=j)
                {
                    k=(a[i]&a[j]);
                }
            }
        }
        cout<<k;
        return 0;
    }
    if(m==1){
        for(int i=1;i<=n;i++)
        {
            if(a[i]>k)k=a[i];
        }
        cout<<k;
        return 0;
    }
    ans=a[n];
    for(int i=n-1;i>=n-m+1;i--)
    {
        ans=(ans&a[i]);
    }
    cout<<ans;
    return 0;
}
