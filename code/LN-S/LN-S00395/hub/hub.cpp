#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> Tree[1123456];
int N, K;
int LTK[1123456];
int Stt;
int hsstt(int i){
    return (Stt&(1<<(i-1)));
}
void dfs(int i, int L){
    if(LTK[i]) return;
    LTK[i] = L;
    for(auto ch:Tree[i]){
        if(hsstt(ch)) dfs(ch, L);
    }
}
int DPH[1123456], PR[1123456], VSS[1123456];
void giveDep(int i, int pr){
    if(VSS[i]) return;
    VSS[i] = 1;

    PR[i] = pr;
    DPH[i] = DPH[pr]+1;

    for(auto ch:Tree[i]){
        giveDep(ch, i);
    }
}
int LCA(int i, int j){
    while(DPH[i]>DPH[j]) i = PR[i];
    while(DPH[i]<DPH[j]) j = PR[j];
    while(i!=j){
        i = PR[i];
        j = PR[j];
    }
    return i;
}
void subtask()
{

    cin>>N>>K;
    for(int i = 1; i <= N; i++){
        Tree[i].clear();
        LTK[i] = 0;
        DPH[i] = PR[i] = 0;
    }
    for(int j = 1; j < N; j++){
        int u, v;
        cin>>u>>v;
        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }
    giveDep(1, 0);

    int mnn = 1111111111111ll;
    for(Stt = 0; Stt < (1<<N); Stt++){
        for(int i = 1; i <= N; i++) LTK[i] = VSS[i] = 0;
        int Ls = 0, Ns = 0;
        for(int i = 1; i <= N; i++){
            if(hsstt(i) && !LTK[i]) dfs(i, ++Ls);

            if(hsstt(i))++Ns;
        }

        if(Ns != K || Ls > 2) continue;

        //方案可行
        //枚举距离
        int mxd = 0;
        for(int a = 1; a <= N; a++){
            int mndss = 1111111111111ll;
            for(int b = 1; b <= N; b++){
                if(!hsstt(b)) continue;
                int lca = LCA(a,b);
                int dss = DPH[a]+DPH[b]-DPH[lca]*2;
        mndss = min(mndss, dss);
            }
                mxd = max(mxd, mndss);
        }
        mnn = min(mnn, mxd);
    }
    cout<<mnn<<endl;
}
signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int c,T;
    cin>>c>>T;
    while(T--) subtask();
}
