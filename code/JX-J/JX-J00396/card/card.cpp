#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],c[300005];
long long n,m;
bool p(int x){
    for(int i=1;i<x;i++){
        if(a[i]==a[x]&&b[i]==0) return true;
    }
    return false;
}
int q(int y){
    for(int i=y-1;i>1;i--){
        if(a[i]==a[y]) return i;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(p(j)==true){
                for(int k=q(j);k<j;k++){
                    b[k]=1;
                }
            }else{
                b[j]=0;
            }
        }
        for(int l=i;l<=n;l++){
            if(b[l]==0){
                c[a[l]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<' ';
    }
    return 0;
}
