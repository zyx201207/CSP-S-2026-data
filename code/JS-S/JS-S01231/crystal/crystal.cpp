#include<bits/stdc++.h>
using namespace std;
int a[500010];
int ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int k=m;
        int cnt=0;
        for(int j=i;j>=1;j--){
            if(k>=(a[i]-a[j])){
                k-=(a[i]-a[j]);
                cnt++;
            }else{
                break;
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
