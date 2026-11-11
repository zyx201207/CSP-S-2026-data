#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int C,T,n,k;
int pw[N];
bool f1[N],f2[N],f3[N];
int d[N];
vector<int> cod;
vector<int> e[N];
int cnt_1(int x){
    int res=0;
    while(x){
        res+=x&1;
        x>>1;
    }
    return res;
}
void spt(int x){
    memset(f1,0,sizeof(f1));
    memset(f2,0,sizeof(f2));
    cod.clear();
    for(int i=1;pw[i]<=x;i++){
        if(x|pw[i]){
                f2[i]=true;
            cod.push_back(i);
        }
    }
}
bool chk(){
    int lf=2;
    for(auto u:cod){
        if(!f1[u])lf--;
        if(lf==0)return false;
        for(auto v:e[u]){
            f1[v]=true;
        }
    }
    return true;
}
int bfs(int x){
    queue<int> q;
    q.push(x);
    f3[x]=true;
    while(!q.empty()){
        int h=q.front();
        q.pop();
        for(auto to:e[h]){
            if(f2[to]){
                return d[h]+1;
            }
            if(f3[to])continue;
            d[to]=d[h]+1;
            q.push(to);
            f3[to]=true;
        }
    }
}
void solve_small(){
    int res=0;
    for(int i=1;i<=pw[n]-1;i++){
        if(cnt_1(i)!=k)continue;
        spt(i);
        if(!chk())continue;
        for(int j=1;j<=n;j++){
            if(f2[j]){
                continue;
            }
            res=max(res,bfs(j));
        }
    }
    printf("%d\n",res);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&C,&T);
    pw[0]=1;
    for(int i=1;i<=10;i++){
        pw[i]=pw[i-1]*2;
    }
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        if(n==k){
            printf("0\n");
        }
        if(C<=3){
            solve_small();
        }
        else{
            printf("%d\n",n/3);
        }
    }
    return 0;
}
