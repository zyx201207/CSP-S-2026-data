#include<bits/stdc++.h>
using namespace std;
int a[500005],c[500005],n,m;
int b[1000009];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            b[j]=a[j];
            for(int k=j-1;k>=1;k--){
                if(b[k]==b[j]){
                    for(int l=j-1;l>=1;l--){
                        b[l]=0;
                    }
                }
            }
        }

        for(int j=1;j<=n;j++){
            c[b[j]]++;
        }
        for(int j=1;j<=n;j++){
            b[j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        if(c[i]>0){
            cout<<c[i]<<" ";
        }
    }
    return 0;

}

