#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[5],c[5];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        }
        for(int j=1;j<=n;j++){
    if(m==1 && (n-j+1)%2!=0)c[1]++;
    if(m!=1){
    for(int i=j;i<=n;i++){
        if(a[i]==1)b[1]++;
        else b[2]++;
    }
    if(b[1]%2!=0)c[1]++;
    if(b[2]%2!=0)c[2]++;
    }}
    cout<<c[1]<<" "<<c[2];
return 0;
}
