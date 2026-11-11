#include<bits/stdc++.h>
using namespace std;
int c,n,m,b,qu,k,t[500010],pre[500010],d[500010];
queue<int>q;
struct STU {
    int to,next,len;
}a[500010];
void add(int u,int v,int len) {
    k++;
    a[k].to=v,a[k].len=len;
    a[k].next=pre[u];
    pre[u]=k;
}
int dj(int x,int t) {
    q.push(x);
    memset(d,0x3f,sizeof(d));
    d[x]=0;
    while(!q.empty()) {
        int h=q.front();
        q.pop();
        for(int i=pre[h];i!=0;i=a[i].next) {
            int to=a[i].to;
            if(d[h]+a[i].len<d[to]) {
                d[to]=d[h]+a[i].len;
                q.push(to);
            }
        }
    }
    return d[t];
}
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>b>>qu;
    for(int i=1;i<=m;i++) {
        cin>>t[i];
    }
    for(int i=1;i<=n;i++) {
        int k,ca=0,ct=0;
        cin>>k;
        int ka,kt;
        cin>>ka>>kt;
        ca=ka,ct=kt;
        for(int j=2;j<=k;j++) {
            cin>>ka>>kt;
            add(ca,ka,ct+kt);
        }
    }
    for(int i=1;i<=qu;i++) {
        int ts,tf;
        cin>>ts>>tf;
        cout<<dj(ts,tf)+t[ts]+t[tf]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
