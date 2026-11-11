#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m,ans;
int a[N];
int cmp(int a,int b){
    return a>b;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int k=a[i]&a[j];
                ans=max(ans,k);
            }
        }
    }else if(m==1){
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
    }else{
        sort(a+1,a+1+n,cmp);
        ans=a[1];
        for(int i=2;i<=m;i++){
            ans=ans&a[i];
        }
    }
    cout<<ans;
}
