#include<bits/stdc++.h>
using namespace std;
int n,m;
int maxn=-114514;
int a[5000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(m==1){
        cout<<maxn;
        return 0;
    } 
    if(m==n) {
        int ans=a[1] & a[2];
        for(int i=3;i<=m;i++){
            ans=ans & a[i];
        }
        cout<<ans;
        return 0;
    }
    return 0;
}