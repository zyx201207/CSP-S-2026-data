#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int d=a[2]-a[1];
    for(int i=2;i<=n;i++){
        if(a[i+1]-a[i]!=d){
            d=-1;
            break;
        }
    }
    if(d!=-1){
        int ans=sqrt(m/d*2);
        for(int i=ans;;i++){
            if(i*(i-1)/2*d<=m){
                ans=i;
            }
        }
        cout<<ans;
        return 0;
    }
    int ans=1;
    for(int i=n;i>=ans;i--){
        int p=m;
        int nowans=1;
        for(int j=i-1;j>=1;j--){
            if(p<a[i]-a[j])break;
            p-=a[i]-a[j];
            nowans++;
        }
        ans=max(nowans,ans);
    }
    cout<<ans;
    return 0;
}//75pts
