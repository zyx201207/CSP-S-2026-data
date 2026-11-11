#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
bool vis[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int cmp=0;
    for(int i=29;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if((!cmp||vis[j])&&(a[j]&(1<<i)))cnt++;
        }
        if(cnt<m)continue;
        for(int j=1;j<=n;j++){
            if(!cmp&&(a[j]&(1<<i)))vis[j]=1;
            if(vis[j]&&!(a[j]&(1<<i)))vis[j]=0;
        }
        ans+=(1<<i);
        cmp=1;
    }
    printf("%d",ans);
    return 0;
}
