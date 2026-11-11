#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],ma;
int main(){
    freopen("and.in","r",std.in);
    freopen("and.out","w",std.out);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            ma=max(ma,a[i]);
        }
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(i!=j){
                    ma=max(ma,a[i] & a[j]);
                }
            }
        }
    }
    if(m==3){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if(i!=j and j!=k){
                        ma=max(ma,a[i] & a[j] & a[k]);
                    }
                }
            }
        }
    }
    cout<<ma;
    return 0;
}
