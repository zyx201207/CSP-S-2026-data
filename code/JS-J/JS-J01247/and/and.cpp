#include<bits/stdc++.h>
using namespace std;
int a[200008];
int n,m;
int ans=0;
int ans2=0;
int ans3=0;
bool d=true;
int main(){
    freopen("ans.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        if(i==1){
            ans2=a[i];
        }
        cin>>a[i];
        ans2&=a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    if(m==1){
        cout<<a[1];
        return 0;
    }
    else if(m==n){
        cout<<ans2;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    return 0;
}