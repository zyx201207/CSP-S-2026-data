#include<bits/stdc++.h>
using namespace std;
int n,s;
long long x[200001],an[200001],mi[200001];
void dfs(int qd,int ti,int lo,int de){
    for(int i=lo+1;i<=n;i++){
        if(x[i]-x[lo]<=s){
            dfs(qd,ti+1,i,de);
        }
    }
    an[ti]++;
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    scanf("%d%d",&c,&T);
    while(T--){
        long long ans=0;
        scanf("%d %d",&n,&s);
        for(int i=1;i<=n;i++){
            scanf("%ld",&x[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                for(int l=1;l<=20000;l++)an[l]=0;
                dfs(j,0,j,i);
                for(int l=1;;l++){
                    if(an[l]!=0 and an[l]==2){
                        ans++;
                        break;
                    }
                    if(an[l]!=0)break;
                }
            }
        }
        printf("%ld\n",ans);
    }
    return 0;
}
