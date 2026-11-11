#include<bits/stdc++.h>
using namespace std;
int c,T,n;
long long d,x[5050],len[5050][5050],t[5050][5050];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--){
        scanf("%d%lld",&n,&d);
        for(int i = 1;i<=n;i++) scanf("%lld",&x[i]);
        for(int i = 1;i<=n;i++) for(int j = 1;j<=n;j++) len[i][j] = 0x3f3f3f3f3f3f3f3f,t[i][j] = 0;
        /*for(int i = 1;i<=n;i++) for(int j = i+1;j<=n;j++){
            if(x[j]-x[i]<=d) len[i][j] = 1,t[i][j] = 1;
            else len[i][j] = 0x3f3f3f3f3f3f3f3f,t[i][j] = 0;
        }for(int l = n;l>=1;l--){
            for(int r = l+2;r<=n;r++){
                for(int k = r-1;k>l&&x[r]-x[k]<=d;k--){
                    if(len[l][k]+1<len[l][r]) len[l][r] = len[l][k]+1,t[l][r] = t[l][k];
                    else if(len[l][k]+1==len[l][r]) t[l][r] += t[l][k];
                }
            }
        }*/
        for(int l = 1;l<=n;l++){
            len[l][l] = 0,t[l][l] = 1;
            int fr = l,bt = 0;
            long long tong[5050] = {};
            tong[len[l][l]] += t[l][l];
            for(int i = l+1;i<=n;i++){
                while(fr<i && x[i]-x[fr]>d) tong[len[l][fr]] -= t[l][fr],fr++;
                if(fr==i) break;
                while(!tong[bt]) bt++;
                len[l][i] = bt+1,t[l][i] = tong[bt];
                tong[len[l][i]] += t[l][i];
            }
        }
        /*for(int l = 1;l<=n;l++){
            for(int r = l+1;r<=n;r++) printf("%lld ",len[l][r]);
            printf("\n");
            for(int r = l+1;r<=n;r++) printf("%lld ",t[l][r]);
            printf("\n");
        }*/
        long long ans = 0;
        for(int l = 1;l<=n;l++) for(int r = l+3;r<=n;r++){
            if(t[l][r]==2){
                ans++;
                //printf("%d %d %lld %lld\n",l,r,len[l][r],t[l][r]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
