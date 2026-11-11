#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const long long N2=9223372036854775807;
int zs,n,m,d,q;
priority_queue<pair<long long,int>,vector<pair<long long,int>>> p;
long long mp[505][505],dis[505],dis2[505][505];
bool fw[505];
int entre[N];
struct platfom{
    int line;
    long long tim;
};
vector<platfom> sta[N];
void zdl(int num){
    for(int i=0;i<505;i++){
        dis[i]=N2;
        fw[i]=false;
    }
    while(p.empty()==false){
        p.pop();
    }
    dis[num]=0;
    p.push({0,num});
    fw[num]=true;
    while(p.empty()==false){
        int id=p.top().second;
        p.pop();
        fw[id]=true;
        for(int i=1;i<=505;i++){
            if(fw[i]==false && mp[id][i]!=0x3f3f3f3f){
                if(dis[i]>dis[id]+mp[id][i]){
                    dis[i]=dis[id]+mp[id][i];
                    p.push({-dis[i],i});
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>zs>>n>>m>>d>>q;
    memset(mp,0x3f3f3f3f,sizeof(mp));
    for(int i=1;i<=m;i++){
        scanf("%d",&entre[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int tim,bh;
            scanf("%d%d",&bh,&tim);
            sta[bh].push_back({i,tim});
        }
    }
    for(int i=1;i<=m;i++){
        int len=sta[i].size();
        for(int j=0;j<len-1;j++){
            for(int e=j+1;e<len;e++){
                if(sta[i][j].tim+sta[i][e].tim<mp[sta[i][j].line][sta[i][e].line]){
                    mp[sta[i][j].line][sta[i][e].line]=sta[i][j].tim+sta[i][e].tim;
                    mp[sta[i][e].line][sta[i][j].line]=sta[i][j].tim+sta[i][e].tim;
                }
            }
        }
    }
    for(int i=0;i<505;i++){
        for(int j=0;j<505;j++){
            dis2[i][j]=N2;
        }
    }
    for(int i=0;i<q;i++){
        int st,ed;
        scanf("%d%d",&st,&ed);
        long long mn=N2;
        for(auto &xl:sta[st]){
            bool zd=false;
            for(auto &xl2:sta[ed]){
                long long ltim1=xl.tim;
                long long ltim2=xl2.tim;
                if(xl.line==xl2.line){
                    mn=ltim1+ltim2;
                    zd=true;
                    break;
                }
                if(dis2[xl.line][xl2.line]!=N2){
                    if(mn>dis2[xl.line][xl2.line]+ltim1+ltim2){
                        mn=dis2[xl.line][xl2.line]+ltim1+ltim2;
                    }
                }else{
                    zdl(xl.line);
                    if(mn>dis[xl2.line]+ltim1+ltim2){
                        mn=dis[xl2.line]+ltim1+ltim2;
                    }
                    for(int i=1;i<=n;i++){
                        if(i!=xl.line && fw[i] && dis[i]!=N2){
                            dis2[xl.line][i]=dis[i];
                            dis2[i][xl.line]=dis[i];
                        }
                    }
                }
            }
            if(zd){
                break;
            }
        }
        long long jz1=entre[st];
        long long jz2=entre[ed];
        mn+=jz1;
        mn+=jz2;
        printf("%lld\n",mn);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
