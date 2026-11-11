#include<bits/stdc++.h>
using namespace std;

const int MAXN = 550;
const int INF = 21e8;

struct Node{
    int to;
    int num;
};

vector<Node > A[MAXN];
vector<Node > B[MAXN];

int c,n,m,d,q;
int W[MAXN];
int st[MAXN], en[MAXN];

void init(){
    cin>> c>> n>>m >> d>> q;
    for(int i=1; i<=m; i++) cin>>W[i];

    for(int i=1; i<=n ;i++){
        int k;  cin>>k;
        for(int j=1; j<=k; j++){

            int u, t;   cin>>u >> t;
            Node a1, a2;
            a1.num = a2.num = t;
            a1.to = i;  a2.to = u;
            A[u].push_back(a1);
            B[i].push_back(a2);
        }
    }

    for(int i=1; i<=q; i++) cin>>st[i] >> en[i];


}

bool A_[MAXN], B_[MAXN];

int ans;

void dfs(int now, bool yes_a, int e, int x){
    if(yes_a && A_[now])    return ;
    if(!yes_a && B_[now])   return ;
    if(yes_a && now == e)   ans = min(ans, x);


    //cout<<now<<" "<<yes_a<<" "<<x<<endl;

    if(yes_a){
        A_[now] = true;
        for(Node X : A[now]){
            dfs(X.to, false, e, x+X.num);
        }

        A_[now] = false;
    }
    else{
        B_[now] = true;
        for(Node X : B[now]){
            dfs(X.to, true, e, x+X.num);
        }

        B_[now] = false;
    }



}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    init();

    for(int p=1; p<=q; p++){
        ans = INF;
        dfs(st[p], true, en[p], 0);
        cout<<ans+W[st[p]] + W[en[p]]<<endl;
    }

    return 0;
}
