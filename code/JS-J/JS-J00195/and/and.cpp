#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m,ans=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            if(a[i]>=ans)ans=a[i];
        }
    }
    else if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i]&a[j]>ans)ans=a[i]&a[j];
            }
        }
    }
    else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
    }
    else ans=255;
    cout<<ans;
    return 0;
}
