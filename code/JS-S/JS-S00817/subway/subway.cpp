#include<bits/stdc++.h>
using namespace std;

#define maxn 600
int c,n,m,d,q;
struct stn{
    int v;
    long long w;
}st[maxn];

struct stp{
    int a;
    long long t;
}tp[maxn];

struct plan{
    int Start;
    int End;
}pl[maxn];

vector<int> M[maxn];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        st[i].v=i;
        cin>>st[i].w;
    }
    for(int i=1;i<=n;i++){
        cin>>tp[i].a>>tp[i].t;
    }
    for(int i=1;i<=n;i++){
        M[tp[i].a].push_back(tp[i].t);
        M[tp[i].t].push_back(tp[i].a);
    }
    for(int i=1;i<=q;i++){
        cin>>pl[i].Start>>pl[i].End;
        int ans=0;
        for(int j=1;j<=m;j++){
            if(M[pl[i].Start][j]==pl[i].End){
                ans+=st[pl[i].Start].w+tp[pl[i].Start].t+st[pl[i].End].w+tp[pl[i].End].t;
                break;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}