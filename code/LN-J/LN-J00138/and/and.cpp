#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[35],ans,c[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<=32;j++){
            b[j]+=((a[i]>>(j-1))&1);
        }
    }
    for(int i=32;i>=1;i--){
        if(b[i]>=m){
            for(int j=1;j<=n;j++){
                if((a[j]>>(i-1))&1)continue;
                if(c[j])continue;
                c[j]=1;
                for(int k=1;k<=32;k++){
                    b[k]-=((a[j]>>(k-1))&1);
                }
            }
            ans+=(1<<(i-1));
        }
    }
    cout<<ans;
    return 0;
}
