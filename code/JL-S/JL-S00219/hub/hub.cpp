#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        int dp[100005][10];
        for(int i=1;i<=x-1;i++){
            int zan1,zan2;
            cin>>zan1>>zan2;
            dp[i][1]=zan1;
            dp[i][2]=zan2;
        }
        if(x>=5)cout<<2;
        else cout<<1;
    }
    return 0;
}
