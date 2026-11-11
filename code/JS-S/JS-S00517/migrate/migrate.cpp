#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200000+11;
ll a[maxn];
int n,d;

struct node{
    int idx,cnt;
}q[maxn];

vector<int> b;

void f(int cnt,int idx){
    if(idx>=n){

        //
        return;
    }else{
        for(int i=1;i<=min(n-idx,d);i++){
            b.push_back(a[idx]);
            //
            f(cnt+1,idx+i);
            //
            b.pop_back();
        }
    }
}

void solve(){
    cin >> n >> d;
    //
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    //
    f();
    //
    /*/
    int dp[maxn];
    dp[1]=0;
    for(int i=2;i<=n;i++){
        int cnt=n;
        //
        for(int j=1;j<=min(i,d);j++){
            cnt=min(cnt,dp[i-j]+1);
            //
            if(cnt>=dp[i-j]+1){
                cnt=dp[i-j]+1;
            }
        }
        //
        dp[i]=cnt;
    }
    //
    for(int i=1;i<=n;i++){
        cout << dp[i] << " ";
    }cout << "\n";
    //
    int b[maxn]={0};
    for(int i=2;i<=n;i++){
        for(int j=1;j<=min(i,d);j++){
            //
        }
    }
    /*/
    //
    return;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    //
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //
    int c,t;
    cin >> c >> t;
    //
    while(t--){
        solve();
    }
    //
    //fclose(stdin);
    //fclose(stdout);
    //
    return 0;
}

/*

0 2
4 2
1 2 3 4

1->2,3
2->3,4
3->4

1 2 3 4

12
123
1234
13
134
23
234
24

1-2 1 2
1-3 1 2
1-4 2 3 :1-2-4,1-3-4
2-3 1 2
2-4 1 2
3-4 1 2


1-2 1 2
1-3 1 2
1-4 2 3 :1-2-4,1-3-4
1-5 1 3
2-3 1 2
2-4 1 2
2-5 2 3 :2-3-5,2-4-5
3-4 1 2
3-5 1 2
4-5 1 2


1 2 3 5 6

1-2
1-3
1-2-3
1-3-5
1-3-5-6



x x xxx
o o ooo
xx x xxx
oo o ooo
x x x xxxx
o o o oooo
xx xx xx xxx
oo oo oo ooo
x x x
o o o
xx x x
oo o o
xxx xxx
ooo ooo
xxxxxxx
ooooooo
xx
oo
xx
oo
x
o
x
o
x
o
x
o
.
.
.
.
.
.
*/
