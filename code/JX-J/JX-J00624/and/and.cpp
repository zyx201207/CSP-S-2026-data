#include <bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+5;
long long n,m,ans=0;
long long a[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(n==m){
        for(int i=0;i<n;i++){
            ans&=a[i];
        }
        cout<<ans<<endl;
        return 0;
    }
    ans=0;
    if(m==1){
        for(int i=0;i<n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans<<endl;
        return 0;
    }
    ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans=max(ans,a[i]&a[j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
