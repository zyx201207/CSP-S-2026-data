#include<bits/stdc++.h>
using namespace std;
int a[501000],d[310000],tot[310000],ans[310000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        d[a[i]]=i;
        tot[a[i]]++;
    }
    for(int i=1;i<=m;i++){
        int j=d[i];
        while(j<=n){
            ans[a[j]]+=tot[i];
            if(j+1<=n)j=d[a[j+1]];
            else break;
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
