#include<bits/extc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;

int n;
ll d;
ll a[N];

int fly_cnt;
ll path_cnt;

void Dfs(int x,int cnt,int ed){
    if(x==ed){
        if(cnt<fly_cnt){
            fly_cnt=cnt;
            path_cnt=1;
        }else if(cnt==fly_cnt) ++path_cnt;
        return;
    }
    for(int y=x+1;y<=ed;++y){
        if(a[y]-a[x]<=d){
            Dfs(y,cnt+1,ed);
        }
    }
}

bool Check(int x,int y){
    fly_cnt=INT_MAX;
    path_cnt=0;
    Dfs(x,0,y);
    return path_cnt==2;
}

void Solve1(){
    ll res=0;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if(Check(i,j)){
                ++res;
            }
        }
    }
    cout<<res<<"\n";
}

int main(){
    auto ___=freopen("migrate.in","r",stdin);
    auto _=freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int c,t; cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;++i) cin>>a[i];
        Solve1();
    }

    return 0;
}

// g++ migrate.cpp -O2 -std=c++14 -static -o test.exe
// ./test.exe < migrate.in > test.out
// diff test.out migrate.ans