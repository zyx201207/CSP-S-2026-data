#include"bits/stdc++.h"
using namespace std;
int c,n,m,d,q;
int x,y;
int w[500010],k[510],t[500010][510];
bool kkstalist[500010];
int statable[500010][510];
long long dfs(int station,int timecost){
    int ans=-1;
    if(station==y){
        return timecost;
    }
    if(kkstalist[station]==true){
        return -1;
    }else{
        kkstalist[station]=true;
    }
    for(int waytry=1;waytry<=n;waytry++){
        if(statable[station][waytry]!=0){
            for(int stry=1;stry<=m;stry++){
                if(statable[stry][waytry]>statable[station][waytry]){
                    int e=dfs(stry,timecost+t[station][waytry]+t[stry][waytry]);
                    if(ans==-1||(e!=-1&&e<=ans)){
                        ans=e;
                    }
                }
            }
        }
    }
    kkstalist[station]=false;
    if(ans==-1){
        return -1;
    }
    return ans;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++){
            int a;
            scanf("%d",&a);
            scanf("%d",&t[a][i]);
            statable[a][i]=j;
        }
    }

    for(int i=1;i<=q;i++){
        scanf("%d%d",&x,&y);
        long long ans=dfs(x,0);
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}
