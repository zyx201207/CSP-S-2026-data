#include<bits/stdc++.h>
using namespace std;

const int MAXN = 310;
const int INF = 21e8;

int n, d;
int a[MAXN];
vector<int > p[MAXN];

int l[MAXN][MAXN];
int len[MAXN][MAXN];

void init(){
    cin>> n>>d;
    memset(a, 0, sizeof(a));
    memset(l, 0, sizeof(l));
    memset(len, 0, sizeof(len));
    for(int i=1; i<=n;i++)  cin>>a[i];

    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(a[j] - a[i] > d) break;
            p[i].push_back(j);
        }
    }

    for(int i=1; i<=n; i++){

        for(int j=1; j<=n; j++){

            len[i][j] = INF;
        }
    }
}

void dfs(int st,int now, int x){
    if(len[st][now] == x)   l[st][now]++;
    else if(len[st][now] > x){
        len[st][now] = x;
        l[st][now] = 1;
    }

    //cout<<now<<" "<<x<<endl;;
    for(int X : p[now]){
        dfs(st, X, x+1);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);


    int c,T;cin>> c>> T;
    while(T--){
        init();

        /*for(int i=1;i<=n; i++){
                cout<<i<<": ";
            for(int J : p[i])   cout<<J<<" ";cout<<endl;
        }*/

        //cout<<endl<<endl<<endl<<"--------------";
        for(int i=1; i<=n; i++){ dfs(i, i, 0);
        }

        int ans = 0;

        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                if(l[i][j] == 2)    ans++;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
