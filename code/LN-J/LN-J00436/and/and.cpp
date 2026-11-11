#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.in","r",stdout);
    int a[5000],n,m;
    cin>>n>>m;
    int maxn=-10;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(a[i],maxn);
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
    }
}
        
    
