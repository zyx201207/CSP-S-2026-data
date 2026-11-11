#include<bits/stdc++.h>
using namespace std;
int b[500005],c[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005],lnc=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];}
    for(int i=1;i<=n;i++){
        lnc=1;
        for(int j=i;j<=n;j++){
            b[lnc]=a[j];
            for(int k=1;k<lnc;k++){
                if(b[k]==b[lnc]){
                    for(int o=k+1;o<=lnc;o++){b[o]=0;}
                    lnc=k+1;
                    break;
                }
            }
            lnc++;
        }
        for(int k=1;k<=lnc;k++){
                c[b[k]]++;
                b[k]=0;
            }
    }
    for(int i=1;i<=m;i++){cout<<c[i]<<" ";}
}
