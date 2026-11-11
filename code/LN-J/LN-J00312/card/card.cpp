#include<bits/stdc++.h>
using namespace std;
const int mxN=5e5+5;
int n,m,a[mxN],c[mxN];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int q[n],p=0,b[n];
        memset(b,0,sizeof(b));
        memset(q,0,sizeof(q));
        for(int j=i;j<=n;j++){
            if(b[a[j]]==1){
                while(q[p]!=a[j]) p--;
            }else{
                q[++p]=a[j];
                b[a[j]]=1;
            }
        }
        for(int k=1;k<=p;k++) c[q[k]]+=1;
    }
    for(int i=1;i<=m;i++) cout<<c[i]<<" ";
    return 0;
}
