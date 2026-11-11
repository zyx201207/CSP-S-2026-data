#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],las[N],mul[N];
int ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        las[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        mul[i]++;
    }
    for(int i=1;i<=n;i++){
        ans[a[i]]+=mul[i];
        mul[las[a[i]]+1]+=mul[i];
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
