#include<bits/stdc++.h>
#define int __int128
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
int X[2123456];
int D[5555][5555];
int C[5555][5555];
int Cnt[5555][5555];
int VV[5555][5555];
void subtask()
{
    int N,Ds;
    //cin>>N>>Ds;
    N = qread();
    Ds = qread();
    for(int i = 1; i <= N; i++){
        //cin>>X[i];
        X[i] = qread();
    }

    if(N > 100000){
        qwrite(0);
        qendl();
    }
    for(int i = 2; i <= N; i++){
        X[i]-=X[1];
    }
    X[1] = 0;
    //极端暴力：枚举i,j，走最短路径，。。。

    //快点阿～～～在等会就写快读拉～～
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            VV[i][j] = 0;
            D[i][j] = INF;
            Cnt[i][j] = 0;
            //if(abs(X[i]-X[j])<=Ds) {
            if(i!=j&&(((X[i]>X[j] && X[i]<=X[j]+Ds) || (X[j]>X[i] && X[j]<=X[i]+Ds)))) {
                C[i][j] = 1;
            }
            else C[i][j] = INF;
        }
    }
    int Ans = 0;
    for(int i = 1; i <= N; i++){
        D[i][i] = 0;
        queue<int> todo;
        todo.push(i);
        while(todo.size()){
            int fr = todo.front();
            todo.pop();

            for(int j = 1; j <= N; j++){
                if(C[fr][j]<INF && D[i][j] > D[i][fr] + C[fr][j]){
                    D[i][j] = D[i][fr] + C[fr][j];
                    todo.push(j);
                }
            }
        }


        todo.push(i);
        Cnt[i][i] = 1;
        while(todo.size()){
            int fr = todo.front();
            todo.pop();

            if(VV[i][fr]) continue;
            VV[i][fr] = 1;

            for(int j = 1; j <= N; j++){
                if(C[fr][j]<INF && D[i][j] == D[i][fr] + C[fr][j]){
                    Cnt[i][j] += Cnt[i][fr];

                    todo.push(j);
                }
            }
        }

        //for(int j = 1; j <= N; j++){cout<<D[i][j]<<" ";}cout<<endl;

        for(int j = i; j <= N; j++){
            if(Cnt[i][j]==2) Ans++;
        }
    }
    //for(int i = 1; i <= N; i++){for(int j = 1; j <= N; j++){cout<<Cnt[i][j]<<" ";}cout<<endl;}

    //cout<<Ans<<endl;
    qwrite(Ans);
    qendl();
}
signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    //luogu-uid 1399239喵，关注fft_type谢谢喵

    int c, T;
    //cin>>c>>T;
    c = qread();
    T = qread();
    while(T--) subtask();
}
