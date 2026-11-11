#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,m;
int a[maxn];
int f[maxn];
int b[maxn];
int w[maxn];
int main(){
     freopen("card.in","r",stdin);
     freopen("card.out","w",stdout);
     cin>>n>>m;
     for(int i=1;i<=n;i++){
        cin>>a[i];
     }
     memset(b,0,sizeof(b));
     for(int i=1;i<=n;i++){
            memset(f,0,sizeof(f));
        for(int j=i;j<=n;j++){
            if(f[a[j]]!=0){
                for(int l=w[a[j]];l<=j;l++){
                    f[a[l]]=0;
                }
                w[a[j]]=j;
                f[a[j]]=1;
            }
                f[a[j]]=1;
                w[a[j]]=j;

        }
        for(int j=i;j<=n;j++){
        for(int k=1;k<=m;k++){
            if(k==a[j]&&f[a[j]]!=0){
                b[k]=b[k]+1;
        f[a[j]]=0;
            }
                    }
     }
     }
     for(int k=1;k<=m;k++){
        cout<<b[k]<<" ";
     }
    return 0;
}
