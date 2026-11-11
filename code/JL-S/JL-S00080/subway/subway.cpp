#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct Code{
    int iia;
    int iit;
};
struct sta{
    int line;
    int pos;
};
long long Way(int poss,int goal,long long tnow,int *w,int *k,Code **s,sta **dp,long long *dpp,int *nl){
    long long re=-1;
    if(dpp[poss]!=-1){return dpp[poss];}
    for(int i=1;i<=nl[poss];i++){
        int linenow=dp[poss][i].line; int tmp=dp[poss][i].pos+1;
        while(tmp<=k[linenow] && nl[tmp]==0){if(s[linenow][tmp].iia==goal){return 0;} tmp++;}
        if(tmp==k[linenow]){return -1;}
        int posstmp=s[linenow][tmp-1].iia;
        if(re==-1){re=Way(posstmp,goal,tnow+s[linenow][poss].iit+s[linenow][posstmp].iit,w,k,s,dp,dpp,nl);}
        else{re=min(Way(posstmp,goal,tnow+s[linenow][poss].iit+s[linenow][posstmp].iit,w,k,s,dp,dpp,nl),re);}

    }
    dpp[poss]=re;
    return re;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    int *w=new int[m+1];
    int *k=new int[n+1];
    for(int i=1;i<=m;i++){scanf("%d",&w[i]);}
    int kmax=0;
    int *nl=new int[m+1];
    for(int i=1;i<=m;i++){nl[i]=0;}
    sta **dp=new sta*[m+1];
    for(int i=1;i<=m;i++){
        dp[i]=new sta[d+1];
    }
    Code **s=new Code*[n+1];
    for(int i=1;i<=n;i++){
        s[i]=new Code[m+1];
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++){
            int tmpa,tmpb;
            scanf("%d%d",&tmpa,&tmpb);
            s[i][j].iia=tmpa; s[i][j].iit=tmpb;
            dp[tmpa][nl[tmpa]++].line=i;
            dp[tmpa][nl[tmpa]].line=j;
        }
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        long long re=w[x]+w[y];
        long long *dpp=new long long[m+1];
        for(int i=0;i<=m;i++){dpp[i]=-1;}
        dpp[y]=0;
        long long ans1=Way(x,y,0,w,k,s,dp,dpp,nl);
        re+=ans1;
        cout<<re<<endl;
    }
    return 0;
}
