#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+100,maxm=3e5+100;
int n,m,a[maxn];int f[maxn];bool tong[maxn];int t[maxn];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        memset(f+i,0,sizeof(int)*(n-i+2));
        memset(tong+i,0,sizeof(bool)*(n-i+2));
        for(int j=i;j<=n;j++){
            if(!tong[a[j]]) tong[a[j]]=1;
            else{
                for(int k=i;k<j;k++){
                    if(a[k]==a[j]) f[k]+=(j-k);
                }
            }
        }
        for(int j=i;j<=n;j=j+1+f[j]){
            t[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++) printf("%d ",t[i]);
    return 0;
}
