#include<bits/stdc++.h>
using namespace std;
int a[10000005],b[10000005],c[10000005],d[10000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,u=1,o=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(b[a[j]]==0){
                b[a[j]]=1;
                c[u]=a[j];
                u++;
            }
            if(b[a[j]]==1){
                for(int k=1;k<=u;k++){
                    if(c[k]==a[j]){
                        o=1;
                    }
                    else if(o==1){
                        b[c[k]]=0;
                        c[k]=0;
                        u--;
                    }
                }
                o=0;
            }
        }
        for(int j=1;j<=u;j++){
            d[c[j]]+=1;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<d[i]<<' ';
    }
    return 0;
}
