#include <bits/stdc++.h>
using namespace std;
int a[300005],b[300005],c[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[i]=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[j]=c[j];
        }
        for(int j=i;j<=n;j++){
            for(int k=j;k>=i;k--){
                if(a[j]==a[k]){
                    for(int x=k;x<j;x++){
                        a[x]=0;
                    }
                }
            }
        }
        for(int j=i;j<=n;j++){
            b[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }


    return 0;
}
