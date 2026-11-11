#include<bits/stdc++.h>
using namespace std;
int n,m;
int t[300005];
int l[300005];
int a[500005];
int f[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n+1;i++){
        f[i]=i;
    }
    for(int i=n;i>=1;i--){
        if(l[a[i]]==0){
            l[a[i]]=i;
            f[i]=0;
        }
        else{
            f[i]=l[a[i]];
        }
    }
    for(int i=1;i<=n;i++){
        int id=i;
        while(id<=n){
            if(f[id]==0){
                t[a[id]]++;
                id++;
            }
            else{
                id=f[id];
            }
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",t[i]);
    }
    return 0;
}
