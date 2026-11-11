#include <bits/stdc++.h>
using namespace std;
int n,m,a[2000005],z=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        for(int i=1;i<=n;i++){
            z=max(z,a[i]);
        }
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                z=max(z,(a[i]&a[j]));
            }
        }
    }
    if(m==3){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    z=max(z,((a[i]&a[j])&a[k]));
                }
            }
        }
    }
    if(m==4){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int o=k+1;o<=n;o++){
                        z=max(z,((a[i]&a[j])&a[k]&a[o]));
                    }
                }
            }
        }
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            z=a[i]&z;
        }
    }
    cout<<z;
}
