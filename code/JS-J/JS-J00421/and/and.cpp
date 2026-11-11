#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,m,tce[N][35];
bool srve[N],rcing;
int ans = 0;
int chk(int x){
    int cnt = 0;
    for(int i = 1;i <= n;i++)
        cnt += (tce[i][x] && srve[i]);
    return cnt;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0);    cout.tie(0);

    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        int x; cin>>x;
        srve[i] = true;
        for(int j = 0;j < 30;j++)
            tce[i][j] = x & (1 << j);
    }

    int lft = n;
    for(int i = 29;i >= 0;i--){
        if(!rcing && chk(i) >= m) rcing = true;
        if(rcing && chk(i) >= m){
            for(int j = 1;j <= n;j++)
                if(tce[j][i] == 0){
                    srve[j] = false;
                    lft--;
                }
            ans += (1 << i);
        }
    }

    cout<<ans;
    return 0;
}
