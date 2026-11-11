#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int c=a[3]-a[2];
    int ans=0;
    int j=0;
    for(int i=1;i<=n;i++)
    {
        ans+=i*c;
        if(ans>m)
        {
            cout<<i;
            return 0;
        }
        if(ans==m)
        {
            cout<<i+1;
            return 0;
        }
    }
    cout<<1;
    return 0;
}

