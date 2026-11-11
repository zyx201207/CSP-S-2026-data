#include<bits/stdc++.h>
using namespace std;
int n,m,ff[600000],b[600000],a[600000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[j]=a[j];
        }
        for(int j=i;j<=n;j++){
            for(int k=i;k<=j;k++){
                if(b[j]==b[k]){
                    for(int t=k;t<=j-1;t++){
                        b[t]=0;
                    }
                }
            }
        }
        for(int j=i;j<=n;j++){
            ff[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ff[i]<<" ";
    }
    return 0;
}
