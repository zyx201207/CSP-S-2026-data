#include<bits/stdc++.h>
using namespace std;
int a[500010],k[300010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("stdin.in","r",stdin);
    freopen("stdin.out","W",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[j];
            for(int k=1;k<=j;k++){
                if(a[j]==a[k]){
                    for(int l=1;l<=n;l++){
                        if(l!=j){
                            a[l]=0;
                        }else a[l]=a[k];
                    }
                }
            }
            for(int q=1;q<n;q++){
                if(a[q]==i){
                    k[i]=i;
                }
            }
        }
    }
    for(int s=1;s<=n;s++){
        if(k[s]!=0){
            cout<<k[s]<<" ";
        }
    }
    return 0;
}
