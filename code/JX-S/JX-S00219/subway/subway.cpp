#include <bits/stdc++.h>
#define p make_pair
using namespace std;
int c,n,m,d,q,w[500001],a[500001],t[500001];
vector<pair<int,int> >h[500001];
int dy(int qd,int zd){
    queue<int>qq;
    bool v[500001];
    int f[500001];
    memset(f,0x3f,sizeof(f));
    memset(v,false,sizeof(v));
    v[qd]=true;
    f[qd]=0;
    qq.push(qd);
    while(!qq.empty()){
        int x=qq.front();
        qq.pop();
        for(int i=0;i<h[x].size();i++){
            int y=h[x][i].first,z=h[x][i].second;
            cout <<y<<' '<<z<<endl;
            if(f[y]>f[x]+z){
                f[y]=f[x]+z;
                if(!v[y]){
                    v[y]=true;
                    qq.push(y);
                }
            }
        }
        cout <<endl;
        v[x]=false;
    }
    return f[zd];
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin >>w[i];
    for(int i=1;i<=n;i++){
        int l;
        cin >>l;
        for(int j=1;j<=l;j++)
            cin >>a[j]>>t[j];
        for(int j=1;j<l;j++)
            for(int k=j+1;k<=l;k++)
                if(j!=k){
                    h[a[j]].push_back(p(a[k],t[k]+t[j]));
                    h[a[k]].push_back(p(a[j],t[k]+t[j]));
                }
    }
    for(int i=1;i<=n;i++){
        int x,y;
        cin >>x>>y;
        cout <<dy(x,y)+w[x]+w[y]<<endl;
    }
    return 0;
}
