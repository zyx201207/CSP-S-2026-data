#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[10010],b[10010],c[10010];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[i]=a[i];
    }
    for(int z=1;z<=n;z++){
    for(int i=1;i<=n;i++){
            int f=0;
        for(int j=1;j<=n;j++){
            if(a[i]==a[j]){
                f=1;
            }
            if(f==1){
                if(j<i){
                    a[j]=0;
                }
            }
        }

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==j){
                b[j]++;
            }
        }
    }
    for(int x=1;x<=n;x++){
        a[x]=c[x];
    }
    a[z]=0;
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
