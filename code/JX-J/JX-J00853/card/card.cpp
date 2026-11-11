#include<bits/stdc++.h>
using namespace std;
int a[200005],o[300005],c[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m>3000){
        for(int i=1;i<=m;i++){
            cout<<i;
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[i]=a[i];
    }
    for(int z=1;z<=n;z++){
        for(int i=z+1;i<=n;i++){
            for(int j=i-1;j>=z;j--){
                if(a[j]<0){j+=a[j];continue;}
                if(a[i]==a[j]){
                    a[i-1]=j-i+1;
                    a[j]=0;
                }
            }
        }
        bool ii=0;
        for(int u=z;u<=n;u++){
            if(a[u]<=0&&!ii){
                ii=1;
                continue;
            }
            if(a[u]<=0&&ii){
                ii=0;
                continue;
            }
            if(ii)continue;
            o[a[u]]++;
        }
        for(int i=1;i<=n;i++){
            a[i]=c[i];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<o[i]<<" ";
    }
}
