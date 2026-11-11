#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.out","w",stdout);
    freopen("crystal.in","r",stdin);
    long long n,m,ans=0;
    cin>>n>>m;
    long long a[n],b[n+1]={0};
    for(long long i=0;i<n;i++){
        cin>>a[i];
        b[i+1]=a[i]+b[i];
    }
    sort(a+0,a+n);

    for(long long i=1;i<n;i++){
        for(long long J=a[1]-a[0];J<=m;J++){
            if((b[i]+J)/i==a[i]){
                ans=i+1;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
