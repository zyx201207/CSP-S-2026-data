#include<bits/stdc++.h>
using namespace std;
int n,m,a[550000],b[430000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int k=1,x[550000]={0},y[550000]={0};
        for(int j=i;j<=n;j++){
            for(int z=j+1;z<=n;z++){
                if(a[z]==a[j]){
                    x[k]=j;
                    y[k]=z-1;
                    k++;
                }
            }
        }
        for(int z=1;z<=k;z++){
            for(int l=x[z];l<=y[z];l++){
                b[l]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<n-b[i]<<" ";
    }
    return 0;
}
