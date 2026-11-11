#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
long long read(){
    long long x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
void write(long long x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
struct node{long long x,step;};
long long n,d,x[maxn],ans=0;
bool BFS(int u,int v){
    int tot[maxn];
    memset(tot,0,sizeof(tot));
    queue<node> q;
    q.push({u,0});
    while(!q.empty()){
        auto t=q.front();
        q.pop();
        if(t.x==v){
            tot[t.step]++;
            continue;
        }
        for(int i=t.x+1;i<=v;++i){
            if(i==v&&t.x==u) continue;
            if(x[i]-x[t.x]<=d){
                q.push({i,t.step+1});
            }
        }
    }
    int i=1;
    while(tot[i]==0){
        i++;
    }
    if(tot[i]==2) return 1;
    else return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long C=read(),t=read();
    while(t--){
        ans=0;
        n=read(),d=read();
        for(int i=1;i<=n;++i) x[i]=read();
        for(int l=1;l<=n-3;++l){
            for(int r=l+3;r<=n;++r){
                ans+=BFS(l,r);
            }
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}
