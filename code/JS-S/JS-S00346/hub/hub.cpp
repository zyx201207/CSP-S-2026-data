#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int c,t;
vector<int>T[maxn];
int res[maxn];
int f1(int u){
    int p[maxn],head=0,tail=0;
    p[++tail]=u;
    res[u]=1;
    while(tail!=head){
        for(auto v:T[p[head+1]]){
            if(!res[v]){
                p[++tail]=v;
                res[v]=1;
            }
        }
        head++;
    }
    return p[tail];
}
int f2(int u){
    int p[maxn],head=0,tail=0;
    p[++tail]=u;
    res[u]=1;
    int sum=0;
    while(tail!=head){
        sum++;
        for(auto v:T[p[head+1]]){
            if(!res[v]){
                p[++tail]=v;
                res[v]=1;
            }
        }
        head++;
    }
    return sum;
}
void slove(){
    int n,k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    int x=f1(1);
    memset(res,0,sizeof(res));
    int len=f2(x);
    cout<<(len-k)/3<<'\n';
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)slove();
    return 0;
}
