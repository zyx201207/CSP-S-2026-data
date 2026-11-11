#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e6+5;
const ll inf=1e9+7;
int a[N]
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }
    if(m==n){
        int ans=a[1];
        for(int i=1;i<=n;i++){
            ans=(ans&a[i]);
        }
        cout<<ans;
        return 0;
    }
    if(m==2){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int aa=(a[i]&a[j]);
                ans=max(ans,aa);
            }
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    cout<<a[n];
    return 0;
}
