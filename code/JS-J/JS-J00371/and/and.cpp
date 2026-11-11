#include <bits/stdc++.h>
using namespace std;
long long chuangjian[200005];

int main(){
    long long ans=0;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>chuangjian[i];
    }
    if(m==1){
        for(int i= 1;i<=n;i++){
            ans=max(ans,chuangjian[i]);

        }
    }
    else if(m==n){
        for(int i=1;i<=n;i++){
            ans=ans & chuangjian[i];
        }
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                long long ans1=chuangjian[i]&chuangjian[j];
                ans=max(ans,ans1);
            }
        }
    }

    cout<<ans;


return 0;}
