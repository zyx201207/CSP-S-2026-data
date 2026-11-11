#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500+11;
int c,n,m,d,q;
int w[maxn];
int k[maxn];
int x,y;

struct node{
    int a,t;
};

vector<int> dv[maxn];
vector<node> a[maxn];

int Min=INT_MAX;

void f(int idx,int row,int ans){
    if(row>y) return;
    //
    if(row==y){
        Min=min(Min,ans);
        //
        return;
    }else{

    }
}

void solve(){
    cin >> x >> y;
    //
    int ans=w[x]+w[y];
    //
    int idx
    f(idx,x,ans);
    //
    return;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    //
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //
    cin >> c;
    //
    cin >> n >> m >> d >> q;
    //
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    //
    int idx=0;
    //
    for(int i=1;i<=n;i++){
        cin >> k[i];
        //
        for(int j=1;j<=k[i];j++){
            int _a,_t;
            //
            cin >> _a >> _t;
            //
            dv[_a].push_back(i);
            a[i].push_back({_a,_t});
        }
    }
    //
    for(int i=1;i<=q;i++){
        solve();
    }
    //
    //fclose(stdin);
    //fclose(stdout);
    //
    return 0;
}
/*
0

2 5 20 2

4 1 9 2 5

3
1 5
2 7
4 6

3
2 3
3 4
5 7

1 3

1 2



1   2   3   4   5
1   1       1
    2   2       2

1->3:

-1       w-1
1->2     t-1,1
2->4x    x
2(1->2(2 t-1,2+t-2,2
2->3     t-2,3
3-       w-3




*/
