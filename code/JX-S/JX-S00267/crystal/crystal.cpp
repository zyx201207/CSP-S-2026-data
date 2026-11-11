#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500001],diff[500001],sum,ans;
bool flag;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==1){
        cout<<1;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)
        diff[i]=a[i+1]-a[i];
    for(int i=2;i<n;i++)
        if(diff[i-1]!=diff[i]) flag=true;
    if(!flag){
        sum=0;
        for(int i=1;i<n;i++)
            if(sum+diff[1]*i<=m) sum+=diff[1]*i;
            else{
                cout<<i;
                return 0;
            }
        cout<<n;
        return 0;
    }
    for(int i=1;i<=n;i++){
        sum=0;
        flag=false;
        for(int j=i;j<=n;j++){
            if(sum+diff[j]*(j-i+1)<=m) sum+=diff[j]*(j-i+1);
            else{
                ans=max(ans,j-i+1);
                flag=true;
                break;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
