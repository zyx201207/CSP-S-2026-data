#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5e5+10;
ll m,n,a[MAXN],l,r,max1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        ll scan=a[i];
        ll sum=0;
        ll ans=0;
        for(int j=i;j>=1;j--){
            sum+=a[i]-a[j];
            if(sum<=m){
                ans++;
            }
            else{
                break;
            }
        }
        max1=max(max1,ans);
    }
    cout<<max1;
    return 0;
}
