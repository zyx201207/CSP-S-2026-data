#include<bits/stdc++.h>
using namespace std;
const int N=666666,M=666;
typedef long long ll;
int case_num,n,m,d,q;
ll w[N],dp[M][M];

struct nd{
    int u;
    ll d;
};
vector<nd> vec[N];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&case_num,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%lld",w+i);
    for(int i=1;i<=n;i++){
        int x; scanf("%d",&x);
        for(int j=1;j<=x;j++){
            int a; ll b;
            scanf("%d%lld",&a,&b);
            vec[a].push_back({i,b});
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        dp[i][j]=1e16;
    for(int i=1;i<=n;i++)
        dp[i][i]=0;
    for(int i=1;i<=m;i++){
        int sz=vec[i].size();
        for(int a=0;a<sz-1;a++) for(int b=a+1;b<sz;b++){
            int lu=vec[i][a].u,ru=vec[i][b].u;
            ll d=vec[i][a].d+vec[i][b].d;
            dp[lu][ru]=min(dp[lu][ru],d);
            dp[ru][lu]=min(dp[ru][lu],d);
        }
    }
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++)   
    //         printf("%lld ",dp[i][j]);
    //     putchar('\n');
    // }
    while(q--){
        int x,y; ll ans=1e17;
        scanf("%d%d",&x,&y);
        for(nd a:vec[x]) for(nd b:vec[y])
            ans=min(ans,a.d+b.d+dp[a.u][b.u]);
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}
//g++ -Wall -std=c++14 -fsanitize=address subway.cpp -o subway;./subway
//diff -s subway7.ans subway_my.out

    //O(nmlogm+qn) is trivial
    //how to go better
    //consider link sth between the routes
    //then U know what to do with the d!
    //that's easy
    //make a 190*500000 match? sounds crazy
    //you facing still a big challenge
    //the good point is that you could floyd
    //well done!
    //the rest?
    //is O(qd^2) acceptable
    //of course
    //that's it
    //200 at last!