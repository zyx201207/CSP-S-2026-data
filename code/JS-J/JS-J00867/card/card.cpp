#include<bits/stdc++.h>
using namespace std;
int num[500010],st[500010],cs[300010],n,m,z;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    for(int i=0;i<n;i++){
        int z=0,c=1,zz=0;
        for(int j=i;j<n;j++){
            for(int k=0;k<z;k++){
                if(st[z]==num[j]){
                    zz=k;
                    c=0;
                    break;
                }
            }
            if(c==1){
                st[z]=num[j];
                z++;
            }else{
                z=zz+1;
            }
        }
        for(int j=0;j<z;j++){
            cs[st[j]]++;
        }
    }
    for(int j=1;j<=m;j++){
            cout<<cs[j]<<' ';
    }
    return 0;
}
