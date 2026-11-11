#include<bits/stdc++.h>
using namespace std;
int n,m,a[50010],b[50010],k[50010],j,i;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            k[j]=a[j];
            for(int l=i;l<=j-1;l++){
                if(k[l]==k[j]){
                    for(int r=l+1;r<=j-1;r++){
                        k[r]=0;
                    }
                    k[j]=0;
                }
            }
        }
        for(j=i;j<=n;j++){
            b[k[j]]++;
            k[j]=0;
        }
    }
    for(i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
