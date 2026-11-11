#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];long long ans,ans2,ans3;int maxn,ans4,ans5;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    ans=a[1];
    ans3=a[2];
    for(int i=2;i<=n;i++){
        if(i>2)ans3&=a[i];
        ans&=a[i];
        if(i==n-1){
            ans2=ans;
        }
    }
    if(m==n){
        cout<<ans;
    }
    if(m==n-1){
        cout<<max(ans2,ans3);
    }
    if(m==1){
        cout<<maxn;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                ans4=max(ans4,max(a[i]&a[j],a[j]&a[i]));
            }
        }
        cout<<ans4;
    }
    if(m==3){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if(i==j||i==k||j==k)continue;
                    ans5=max(ans5,a[i]&a[j]&a[k]);
                }
            }
        }
        cout<<ans5;
    }
    return 0;
}
