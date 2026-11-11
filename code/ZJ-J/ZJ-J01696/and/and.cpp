#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m,a[maxn];
bool ok[maxn];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ok[i]=true;
    }
    int ans=0;
    for(int i=30;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(ok[j]&&((a[j]>>i)&1)==1){
                cnt++;
            }
        }
        if(cnt<m) continue;
        for(int j=1;j<=n;j++){
            if(ok[j]&&((a[j]>>i)&1)==0){
                ok[j]=false;
            }
        }
        ans|=(1<<i);
    }
    printf("%d\n",ans);
    return 0;
}