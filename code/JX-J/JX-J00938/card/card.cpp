#include <bits/stdc++.h>
using namespace std;
int a[500005],b[500005],guo[300005];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
            int x=1;
        for(int j=1;j<=n;j++){
            b[j]=0;
        }
        for(int j=1;j<=n-i+1;j++){
            b[x]=a[i+j-1];
            for(int y=1;y<x;y++){

                if(b[y]==b[x]){
                    for(int z=y+1;z<=x;z++){
                        b[z]=0;

                    }
            break;
                }
            }
            x++;
        }
        for(int j=1;j<=x;j++){
            guo[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<guo[i]<<" ";
    }
    return 0;
}
