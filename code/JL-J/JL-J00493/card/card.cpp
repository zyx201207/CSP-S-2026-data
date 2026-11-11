#include<bits/stdc++.h>
using namespace std;
int m,n,a[5000],b[5000],c[3000];
int main(){
    freopen ("card.in","r",stdin);
    freopen ("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int xb=1;
    for(int k=1;k<=n;k++){
        xb=1;
        for(int i=k;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(b[j]==a[i]){
                        xb=j;
                        j=i+1;
                }
            }
            b[xb]=a[i];
            xb++;
        }
        for(int i=1;i<=xb;i++){
            c[b[xb]]++;
        }
    }
    for(int i=1;i<=3000;i++){
        if(c[i]){
            cout<<c[i]<<" ";
        }
    }
    return 0;
}
