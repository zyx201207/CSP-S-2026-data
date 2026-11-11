#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[500005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int b[300005]={};
    for(int i=1;i<=n;i++){
        int x[500005]={};
        bool f[500005]={};
        int w=1;
        for(int j=i;j<=n;j++){
            if(f[a[j]]==0){
                f[a[j]]=1;
                x[w]=a[j];
                w++;
            }else{
                w--;
                while(x[w]!=a[j]){
                    x[w]=0;
                    f[x[w]]=0;
                    w--;
                }
                w++;
            }
        }
        for(int j=1;j<w;j++){
            b[x[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
