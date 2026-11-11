#include<bits/stdc++.h>
using namespace std;
int n,m,k,l;
int a[500005];
int s[500005];
int g[500005][3];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        k=0;
        for(int j=i;j<=n;j++){
            l=0;
            if(g[a[j]][1]!=0){
                l=1;
                for(int v=1;v<=k;v++){
                    if(g[v][1]>g[a[j]][1]){
                        g[v][1]=0;
                        g[a[j]][2]=0;
                        l++;
                    }
                }
                if(l==1) l=0;
            }
            k-=l;
            k++;
            g[k][1]=k;
            g[k][2]=a[j];
        }
        for(int j=1;j<=k;j++){
            if(g[j][1]!=0) s[g[j][2]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<s[i]<<" ";
    }
    return 0;
}
