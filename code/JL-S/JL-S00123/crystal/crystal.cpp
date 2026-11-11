#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,a[50000],sum,m,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    for(int i=1;i<=n;i++){
        if(a[i]==a[i++]&&a[i]==a[i]){
           for(int j=1;j<=m;j++){
            sum+=a[i];
           }
           cnt++;
        }

    }
    cout<<cnt;

    return 0;
}
