#include<bits/stdc++.h>
using namespace std;

const int N=5*1e5+10;
int n,m,a[N],k,f[N],b[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int i=1;i<=m;i++){
            b[i]=0;
        }
        for(int j=i;j<=n;j++){
            b[a[j]]=1;
        }
        for(int j=1;j<=m;j++){
            if(b[j]==1){
                f[j]+=1;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<f[i]<<" ";
    }
    return 0;
}
