#include<bits/stdc++.h>
using namespace std;
int n,m,a[50005],g[50005],s[50005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            g[j]=a[j];
        }
        for(int j=i+1;j<n;j++){
            if(g[j]==a[i]){

            }
        }
    }

    return 0;
}
