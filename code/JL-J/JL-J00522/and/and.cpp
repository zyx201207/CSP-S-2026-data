#include<bits/stdc++.h>
using namespace std;
int n,m,sum,a[200001];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1){
            sum=a[1];
        }else{
            sum=sum&a[i];
        }
    }
    int ans=0;
    if(n==m){
        cout<<sum;
        return 0;
    }
    if(m==n-1){
        for(int i=1;i<=n;i++){
            ans=max(ans,sum&a[i]);
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    if(m==2){
        n=min(n,2001);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j){
                    continue;
                }
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==1){
        cout<<a[1];
        return 0;
    }
    for(int i=1;i<=m;i++){
        if(i==1){
            ans=a[1];
        }else{
            ans=ans&a[i];
        }
    }
    cout<<ans;
    return 0;
}
