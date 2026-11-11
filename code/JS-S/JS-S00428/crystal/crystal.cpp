#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[500005];
ll cha[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int ans=1;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++) cha[i]=a[i+1]-a[i];
    for(int i=1;i<n;i++){
        ll he=cha[i];
        int k=i+1;
        while(cha[k]*(k-i+1)<=(m-he) && k<=n){
            he+=cha[k]*(k-i+1);
            k++;
        }
        ans=max(ans,k-i+1);
    }
    cout<<ans;
    return 0;
}
