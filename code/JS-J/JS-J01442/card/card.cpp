#include<bits/stdc++.h>
#define N 500
using namespace std;
int a[N],x[N],v[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];}
    for(int i=1;i<=n;i++){
        int t=0;bool f=0;
        for(int j=i-1;j<=n;j++){
            f=0;
            for(int k=0;k<t;k++){
                if(a[j]==x[k]){
                    for(int il=t;il>=k;il--){
                        x[il]=0;t--;
                    }
                }
            }
            x[t]=a[j];
        }
        for(int j=1;j<=n;j++){
            v[x[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<v[i]<<' ';
    }
    return 0;
}
