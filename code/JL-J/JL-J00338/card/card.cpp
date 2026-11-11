#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int to[N];
int lst[N];
int cnt[N];
int ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=n;i>=1;i--){
        int nxt=lst[a[i]];
        if(nxt==0){
            to[i]=i+1;
        }
        else{
            to[i]=to[nxt];
        }
        lst[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        cnt[i]++;
        ans[a[i]]+=cnt[i];
        cnt[to[i]]+=cnt[i];
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
