#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long f[500005];
struct A{
    long long sl,wz;
}g[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(g[a[j]].sl==1){
                for(int k=g[a[j]].wz;k<j;k++){
                    g[a[k]].sl=0;
                }
            }
            g[a[j]].sl=1;
            g[a[j]].wz=j;
        }
        for(int j=i;j<=n;j++){
            if(g[a[j]].sl>0&&g[a[j]].wz==j){
                f[a[j]]++;
            }
            g[a[j]].sl=0;
            g[a[j]].wz=0;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<f[a[i]]<<" ";
    }
    return 0;
}
