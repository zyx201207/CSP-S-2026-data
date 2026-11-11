#include<bits/stdc++.h>
using namespace std;
int n,m,a[501000],f=0,b[301000]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int table[501000],lo=0;
        for(int j=i;j<=n;j++){
            f=0;
            for(int k=1;k<=lo;k++){
                if(table[k]==a[j]){
                    lo=k;
                    f=1;
                    break;
                }
            }
            if(f==0){
                lo++;
                table[lo]=a[j];
            }
        }
        for(int j=1;j<=lo;j++){
            b[table[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
