#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int p[1005];
int z;
int l[1005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=m;k++){
            p[k]=0;
        }
        z=0;
        for(int j=i;j<=n;j++){
            int e=0;
            for(int k=1;k<=z;k++){
                if(p[k]==a[j]){
                    e=k;
                    break;
                }

            }
            z++;
            p[z]=a[j];
            if(e!=0){
                for(int k=e-1;k<=z;k++){
                    p[k-e]=p[k];
                }
                z-=e;
            }
        }
        for(int k=1;k<=z;k++){
            l[p[k]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<l[i]<<" ";
    }
    return 0;
}
