//TODO: duipai
#include<bits/stdc++.h>
#define int long long
using namespace std;


int qread(void){
    int flg = 1, c = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch=='-') flg = -flg;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        c *= 10;
        c += ch-'0';

        ch = getchar();
    }
    return flg*c;
}
void qwrite(int x){
    if(x < 0){
        putchar('-');
        qwrite(-x);
        return;
    }
    if(x < 10) {
        putchar(x+'0');
        return;
    }
    qwrite(x/10);
    putchar((x%10)+'0');
}
void qspace(void){putchar(' ');}
void qendl(void){putchar('\n');}


const int INF = 1111111111111ll;
typedef pair<int, int> pir;//先权后点
int C,N,M,d,Q;
int K[555];
vector<int> A[555], T[555];
int W[512346];
vector<pair<int, int> > subs[512345];

int D[555][555];

int mnT[555];


int SIZE=0;

int Vis[555], Dis[555];
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);
    //cin>>C>>N>>M>>d>>Q;
    C = qread();
    N = qread();
    M = qread();
    d = qread();
    Q = qread();
    SIZE = N;

    for(int m = 1; m <= M; m++) W[m]=qread();

    for(int i = 1; i <= N; i++){
        K[i]=qread();
        A[i].push_back(0);
        T[i].push_back(0);
        //0-index => 1-index

        for(int k = 1; k <= K[i]; k++){
            int a,t;
            //cin>>a>>t;
            a = qread();t=qread();
            A[i].push_back(a);
            T[i].push_back(t);
            subs[a].push_back(make_pair(i, k));
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            D[i][j] = INF;
        }
        D[i][i] = 0;
    }
    for(int i = 1; i <= N; i++){
        for(int k = 1; k <= K[i]; k++){
            for(auto jr:subs[A[i][k]]){
                int j = jr.first, kk = jr.second;
                D[i][j] = min(D[i][j], T[i][k]+T[j][kk]);
                D[j][i] = min(D[j][i], T[i][k]+T[j][kk]);
            }
        }
    }

    //考虑到
    //当你确定好开始和结束的地铁后
    //只需要在地铁间专乘
    //于是
    //我们令D[a][b]表示由线路a直接转到线路b的代价

    //先玩玩floyd

    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            if(D[i][k] >= INF) continue;//剪个枝
            for(int j = 1; j <= N; j++){
                D[i][j] = min(D[i][j], D[i][k]+D[k][j]);
            }
        }
    }
    //先考虑这个图
    //应该是一个稠密图
    //Dijkstra的表现并不好。
    //大约是单次O((n+m)logn)即O(n^2logn)
    //总复杂度O(n^3logn)
    //还不如你floyd哥

    //想一个更好的方法
    //对于一次询问，我们直接枚举
    for(int q = 1; q <= Q; q++){
        int i, j;
        cin>>i>>j;
        //时间够的啊啊啊
        int mn = INF;
        for(auto iq:subs[i]){
            for(auto jq:subs[j]){
                int it = T[iq.first][iq.second];
                int jt = T[jq.first][jq.second];
                int ij = D[iq.first][jq.first];

                int sm = W[i]+W[j]+it+jt+ij;
                mn = min(mn, sm);
            }
        }

        //cout<<mn<<endl;
        qwrite(mn);
        qendl();
    }
}
