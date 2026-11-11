#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],n,m,flag[N][32],res,st[N];
void init(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
}
signed main(){
    init();
    //freopen("and5.in","r",stdin);
    //freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;j<=30;j++){
            if((1<<j)&a[i]) flag[i][j]=1;
        }
        st[i]=1;
    }
    for(int i=30;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(!st[j]) continue;
            if(flag[j][i]) cnt++;
        }
        if(cnt<m) continue;
        res+=(1<<i);
        for(int j=1;j<=n;j++){
            if(!flag[j][i]) st[j]=0;
        }
    }
    cout<<res<<"\n";
    return 0;
}
