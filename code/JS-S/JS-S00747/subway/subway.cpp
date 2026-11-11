#include<bits/stdc++.h>
//地铁
using namespace std;
long long  w[500005];
int l[500005][505];

int main(){
    freopen("subway4.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long c,n,m,d,q;

    cin>>c>>n>>m>>d>>q;

    for(long long i = 0;i < m;++i){
        cin>>w[i + 1];//time
    }

    for(long long i = 0;i < n;++i){
        long long num = 0;
        cin>>num;
        for(long long j = 0;j < 2;++j){
            int a,t;
            cin>>a>>t;
            l[a][j] = t;
            l[a][j] = t;
        }
    }
    long long ans = 0;
    for(long long i = 0;i < q;++i){
        long long x,y;
        cin>>x>>y;
        if(7<= c && 11 >= c){//A
            ans += w[x] + w[y] + l[x][1] + l[y][0];
            for(long long j = x;j <= y;j++){
                ans += l[j][0] + l[j][1];



                    }
                }

    cout<<ans<<'\n';
        }
}
