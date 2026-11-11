#include<bits/stdc++.h>
using namespace std;
const int kmaxn=2e6+10;
int idT,T;
int n,K;
vector<int>to[kmaxn];
vector<int>F;//直径
bool pt[kmaxn];//是否在直径上
int Nd[kmaxn][2];//给左边给右边
int Dep[kmaxn],Ip[kmaxn];//深度最大点，对应编号
int ANS,tA,tB;
void Dfs(int x,int f){//找到直径
    Dep[x]=0;Ip[x]=x;
    pair<int,int>ma,se;//深度最大的两个点
    ma={x,0};se={0,0};
    for(int i:to[x]){
        if(i==f)continue;
        Dfs(i,x);
        if(Dep[i]+1>ma.second){
            swap(ma,se);ma={Ip[i],Dep[i]+1};
        }else{
            if(Dep[i]+1>se.second){
                se={Ip[i],Dep[i]+1};
            }
        }
        if(Dep[x]<Dep[i]+1){
            Dep[x]=Dep[i]+1;
            Ip[x]=Ip[i];
        }
    }
    if(se.first){
        if(ANS<ma.second+se.second){
            tA=ma.first;tB=se.first;ANS=ma.second+se.second;
        }
    }
    return ;
}
bool sol(int x,int f){
    if(x==tB){
        F.push_back(x);
        return 1;
    }
    bool qq=0;
    for(int i:to[x]){
        if(i==f)continue;
        qq|=sol(i,x);
    }
    if(qq)F.push_back(x);
    return qq;
}
int V;
int Ma[kmaxn][2];
void dfs(int x,int f){
    Dep[x]=0;
    Nd[x][0]=Nd[x][1]=0;
    for(int i:to[x]){
        if(i==f||pt[i])continue;
        dfs(i,x);
        Dep[x]=max(Dep[x],Dep[i]+1);
        Nd[x][0]+=Nd[i][0];Nd[x][1]+=Nd[i][1];
    }
    if(Dep[x]>=V&&f)Nd[x][0]++,Nd[x][1]++;
    return ;
}
void DFS(int x,int f){
    Dep[x]=0;
    Nd[x][0]=0;
    for(int i:to[x]){
        if(i==f)continue;
        DFS(i,x);
        Dep[x]=max(Dep[x],Dep[i]+1);
        Nd[x][0]+=Nd[i][0];
    }
    if(Dep[x]>=V)Nd[x][0]++;
    return ;
}
int TT=0;
int cnt=0,pr[kmaxn],WW=0;//可行的最低黑点位置
vector<int>RR;
vector<pair<int,int> >QP;//ma-2*dep
int lst=0;
void DF(int x,int f,int ddp){//外部最长
    RR.push_back(x);
    //ma-2*dep+ddp>V的最后一个位置
    lst=min(lst,(int)QP.size()-1);
    lst=max(lst,0);
    while(lst+1<QP.size()&&QP[lst+1].first+QP[lst+1].second*2+ddp>V){
        lst++;
    }
    if(lst<QP.size()&&QP[lst].first+QP[lst].second*2+ddp>V){
        int ct=QP[lst].first+2*QP[lst].second-V;//ct必须是黑色的
        if(ct>0)TT=TT;
        else TT=min(TT,Nd[x][0]);
    }else{
        TT=min(TT,Nd[x][0]);
    }
    int old=WW;
    int ma=0,se=0,sum=0;
    for(int i:to[x]){
        if(i==f)continue;
        sum+=Nd[i][0];
        if(ma<Dep[i]+1){
            swap(ma,se);ma=Dep[i]+1;
        }else{
            if(se<Dep[i]+1)se=Dep[i]+1;
        }
    }
    int odlst=lst;
    for(int i:to[x]){
        if(i==f)continue;
        int pc=(Dep[i]+1==ma?se:ma)+ddp;//这个子树内其他点最大深度
        vector<pair<int,int> >DD;
        while(QP.size()&&QP.back().first-2*QP.back().second<pc-2*ddp){
            DD.push_back(QP.back());QP.pop_back();
        }
        QP.push_back({pc-2*ddp,ddp});
        DF(i,x,ddp+1);
        QP.pop_back();
        while(DD.size()){
            QP.push_back(DD.back());
            DD.pop_back();
        }
        lst=odlst;
    }
    RR.pop_back();
}
bool PFFF=1;
bool check(int sz){//是否合法？
    V=sz;
    int Len=F.size()-1;
    if(sz*2>=Len)return 1;
    int RtA=F[sz],RtB=F[Len-sz];
    for(int i=sz;i<=Len-sz;i++){
        dfs(F[i],0);
        Ma[i][0]=(i-sz)+Dep[F[i]];
        Ma[i][1]=(Len-sz-i)+Dep[F[i]];
//        cout<<sz<<" "<<F[i]<<" "<<Dep[F[i]]<<" "<<Ma[i][0]<<" "<<Ma[i][1]<<" "<<Nd[F[i]][0]<<" "<<Nd[F[i]][1]<<"!\n";
    }
    Ma[sz][0]=Ma[Len-sz][1]=sz;
    for(int i=sz+1;i<=Len-sz;i++)Ma[i][0]=max(Ma[i][0],Ma[i-1][0]),Nd[F[i]][0]+=Nd[F[i-1]][0];
    for(int i=Len-sz-1;i>=sz;i--)Ma[i][1]=max(Ma[i][1],Ma[i+1][1]),Nd[F[i]][1]+=Nd[F[i+1]][1];
    for(int i=sz;i<Len-sz;i++){
        if(Ma[i][0]+Ma[i+1][1]+2-2*sz+Nd[F[i]][0]+Nd[F[i+1]][1]<=K)return 1;
    }
    //否则把中间填满了还能选一个
    return 0;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>idT>>T;
    while(T--){
        cin>>n>>K;
        F.clear();
        for(int i=1;i<=n;i++){
            to[i].clear();pt[i]=0;
        }
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            to[u].push_back(v);
            to[v].push_back(u);
        }
        ANS=0;
        Dfs(1,0);
        sol(tA,0);
        for(int i:F){
            pt[i]=1;
        }
        int L=-1,R=n+1;
        L=-1;R=n+1;
        while(L+1<R){
            int mid=(L+R)/2;
            if(check(mid))R=mid;
            else L=mid;
        }
        cout<<R<<"\n";
    }
}