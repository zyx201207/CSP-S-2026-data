#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m;
ll a[N];
int ans=0;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    

    for(int i=1;i<=n;i++){
        ll sum=0;int j;
        for(j=i;j>=1;j--){
            
            sum+=a[i]-a[j];
            if(sum>m){
                break;
            }
        }
        //cout<<i<<' '<<j<<' '<<sum<<endl;
        ans=max(i-j,ans);
    }
    cout<<ans;
    return 0;
}