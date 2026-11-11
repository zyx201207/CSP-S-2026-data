#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,xlnum,ql,zl,sx,zx;
long long ans = 0;
int w[500010],k[510];
struct T{
    int a,t;
}sw[510][500010];
string st[510];
bool is = false;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i = 0;i < m;i++){
        scanf("%d",&w[i]);
    }
    for(int i = 0;i < n;i++){
        scanf("%d",&k[i]);
        for(int j = 0;j < k[i];j++){
            scanf("%d%d",&sw[i][j].a,&sw[i][j].t);
            st[i] += to_string(sw[i][j].a);
        }
    }
    while(q--){
        scanf("%d%d",&sx,&zx);
        char s = sx + '0';
        char z = zx + '0';
        for(int i = 0;i < n;i++){
            if(st[i].find(s) != -1 && st[i].find(z) != -1){
                is = true;
                xlnum = i;
                break;
            }
        }
        if(is){
            for(int i = 0;i < k[xlnum];i++){
                if(sw[xlnum][i].a == sx || sw[xlnum][i].a == zx){
                    ans += sw[xlnum][i].t;
                }
            }
            ans = ans + w[sx - 1] + w[zx - 1];
            printf("%lld\n",ans);
        }else{
            for(int i = 0;i < n;i++){
                if(st[i].find(s) != -1){
                    ql = i;
                }else if(st[i].find(z) != -1){
                    zl = i;
                }
            }
            for(int i = 0;i < k[ql];i++){
                for(int j = 0;j < k[zl];j++){
                    if(st[ql][i] == st[zl][j]){
                        for(int x = 0;x < k[ql];x++){
                            int a1 = sw[ql][x].a;
                            int a2 = st[ql][i] - '0';
                            if(a1 == a2){
                                ans += sw[ql][x].t;
                                break;
                            }
                        }
                        for(int x = 0;x < k[zl];x++){
                            int a1 = sw[zl][x].a;
                            int a2 = st[zl][j] - '0';
                            if(a1 == a2){
                                ans += sw[zl][x].t;
                                break;
                            }
                        }
                    }
                }
            }
            for(int i = 0;i < k[ql];i++){
                if(sw[ql][i].a == sx){
                    ans += sw[ql][i].t;
                    break;
                }
            }
            for(int i = 0;i < k[zl];i++){
                if(sw[zl][i].a == zx){
                    ans += sw[zl][i].t;
                    break;
                }
            }
            ans = ans + w[sx - 1] + w[zx - 1];
            printf("%lld\n",ans);
        }
        xlnum = 0,ql = 0,zl = 0,ans = 0;
        is = false;
    }
    return 0;
}
