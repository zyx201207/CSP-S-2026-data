#include<bits/stdc++.h>
using namespace std;
int a[20005],ck[30005],n,m,c[20005],b[30005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) ck[j]=-1;
        for(int j=i;j<=n;j++){
            c[j]=a[j];
            if(ck[a[j]]!=-1){
                for(int k=ck[a[j]];k<j;k++){
                    ck[c[k]]=-1;
                    c[k]=0;
                }
            }
            ck[a[j]]=j;
        }
        for(int j=i;j<=n;j++) {
            b[c[j]]++;
        }
        for(int j=i;j<=n;j++) c[j]=0;
    }
    for(int i=1;i<=m;i++) cout<<b[i]<<" ";
    return 0;
}
