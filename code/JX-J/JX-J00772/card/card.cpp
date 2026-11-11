#include<bits/stdc++.h>
using namespace std;
int a[1000000],b[1000000],m,n,cut[1000000],no;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
   }
    for(int i=1;i<=n;i++){
        for(int k=i;k<=n;k++){
            b[k]=a[k];

        }
        for(int j=i;j<=n;j++){
            if(b[j]==-1)continue;
            no=0;
            for(int k=n;k>j;k--){
                if(b[k]==b[j]){
                    no=k;
                    break;
                    }
            }if(no!=0){
                for(int k=j;k<no;k++){
                    b[k]=-1;
                }
            }
        }for(int k=i;k<=n;k++){
                cut[b[k]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cut[i]<<" ";
    }
    return 0;
}
