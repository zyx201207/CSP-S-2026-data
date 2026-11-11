#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10,maxm=3e5;
int n,m,a[maxn],cnt[maxn],mxpos[maxm],ans[maxm];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        mxpos[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        cnt[i]++;
        ans[a[i]]+=cnt[i];
        cnt[mxpos[a[i]]+1]+=cnt[i];
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}