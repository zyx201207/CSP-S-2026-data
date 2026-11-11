#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
long long a[N],m,n;
long long ans,t[N];
struct node{
    long long u,v,w;
};
vector <node> g;

struct father{
    int f;
    long long cnt;
    long long num,maxn;
}fa[N];
int fd(int x){
    if (fa[x].f == x) return x;
    return fa[x].f = fd(fa[x].f);
}

void add(int a,int b){
    int aa = fd(a),bb = fd(b);
    fa[aa].f = bb;
    fa[bb].num += fa[aa].cnt * abs(fa[aa].maxn - fa[bb].maxn) + fa[aa].num;
    fa[aa].maxn = fa[bb].maxn = max(fa[aa].maxn,fa[bb].maxn);
    fa[bb].cnt += fa[aa].cnt;
}

bool cmp(node a,node b){
    return a.w < b.w;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    bool flag = 1;
    long long last = -1;
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        fa[i].f = i;fa[i].cnt = 1;
        cin >> a[i];
        if (i == 1) continue;
        if (i == 2) last = a[i] - a[i - 1];
        else if (a[i] - a[i - 1] != last){
            flag = 0;
            last = a[i] - a[i - 1];
        }
    }
    if (flag){
        cout << m / last;
    }
    else{
        sort(a + 1,a + n + 1);
        fa[1].maxn = a[1];
        for (int i = 2;i <= n;i++){
            fa[i].maxn = a[i];
            g.push_back((node){i - 1,i,a[i] - a[i - 1]});
        }
        //sort(g.begin(),g.end(),cmp);
        for (int i = 0;i < g.size();i++){
            node f = g[i];
            int uu = fd(f.u),vv = fd(f.v);
            if (uu != vv && fa[uu].cnt * abs(fa[uu].maxn - fa[vv].maxn) + fa[uu].num <= m){
                add(uu,vv);
            }
        }
        for (int i = 1;i <= n;i++){
            int ii = fd(i);
            t[ii]++;
            ans = max(ans,t[ii]);
        }
        cout << ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
