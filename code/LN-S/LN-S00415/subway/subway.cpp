#include<bits/stdc++.h>
using namespace std;
/*m 个地铁站，n 条地铁线路，,每个地铁站最多有 d 条线路经过,有 q 个出行计划
第 i 条线路经过 jg i 个地铁站,在第 a i,j 个地铁站处,从站厅走到第 i条线路的站台需要 t i,j 的时间*/
int c,n,m,d,q,w[500005],jg[505],e[505][25],as[505][505];
bool stt[505];
struct node{
int a,x;
}a[505][1005];
node p[5][250005];
queue<int>f;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(c==20||c==21){
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=n;i++){
            cin>>jg[i];
            for(int j=1;j<=jg[i];j++){
                int x,y;
                cin>>x>>y;
                p[i][j]={x,y};
                e[x][0]++;
                e[x][e[x][0]]=i;
            }
        }
            memset(as,0x7f7f7f7f,sizeof(as));
        for(int i=1;i<=q;i++){
            while(!f.empty())f.pop();
            int st,fi,ans=0;
            cin>>st>>fi;
            if(stt[st]){
                cout<<as[st][fi]+w[st]+w[fi]<<endl;
                continue;
            }
            f.push(st);
            as[st][st]=0;
            stt[st]=1;
            int aaa=0;
            while(!f.empty()&&aaa<1e7){
                //aaa++;
                int x=f.front();
                f.pop();
                for(int j=1;j<=e[x][0];j++){
                    int l=e[x][j],qqq;
                    for(int k=1;k<=jg[l];k++)if(p[l][k].a==x)qqq=k;
                    for(int k=1;k<=jg[l];k++){
                        if(p[l][k].a!=x){
                                if(as[st][p[l][k].a]>as[st][x]+p[l][qqq].x+p[l][k].x){
                                    as[st][p[l][k].a]=as[st][x]+p[l][qqq].x+p[l][k].x;
                                    f.push(p[l][k].a);
                                }

                        }
                    }
                }
            }
            cout<<as[st][fi]+w[st]+w[fi]<<endl;
        }
        return 0;
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>jg[i];
        for(int j=1;j<=jg[i];j++){
            int x,y;
            cin>>x>>y;
            a[i][j]={x,y};
            e[x][0]++;
            e[x][e[x][0]]=i;
        }
    }
        memset(as,0x7f7f7f7f,sizeof(as));
    for(int i=1;i<=q;i++){
        while(!f.empty())f.pop();
        int st,fi,ans=0;
        cin>>st>>fi;
        if(stt[st]){
            cout<<as[st][fi]+w[st]+w[fi]<<endl;
            continue;
        }
        f.push(st);
        as[st][st]=0;
        stt[st]=1;
        int aaa=0;
        while(!f.empty()&&aaa<1e7){
            //aaa++;
            int x=f.front();
            f.pop();
            for(int j=1;j<=e[x][0];j++){
                int l=e[x][j],qqq;
                for(int k=1;k<=jg[l];k++)if(a[l][k].a==x)qqq=k;
                for(int k=1;k<=jg[l];k++){
                    if(a[l][k].a!=x){
                            if(as[st][a[l][k].a]>as[st][x]+a[l][qqq].x+a[l][k].x){
                                as[st][a[l][k].a]=as[st][x]+a[l][qqq].x+a[l][k].x;
                                f.push(a[l][k].a);
                            }

                    }
                }
            }
        }
        cout<<as[st][fi]+w[st]+w[fi]<<endl;
    }
    return 0;
}
