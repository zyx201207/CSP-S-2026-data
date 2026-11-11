#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+10;
int a[MAXN],b[35][MAXN],st[MAXN];
int n,m;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        st[i]=1;
        for(int j=30;j>=0;j--) b[j][i]=(a[i]>>j)&1;
    }

    for(int i=30;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++) if(st[j]) cnt+=b[i][j];
        if(cnt<m) continue;
        // cnt>=m
        for(int j=1;j<=n;j++){
            if(!b[i][j]) st[j]=0;
        }
        if(cnt==m) break;
    }

    int cnt=0,ans=0,flag=0;
    for(int i=1;i<=n;i++){
        if(cnt>=m) break;
        if(st[i]){
            if(!flag) ans=a[i], flag=1;
            else ans=ans&a[i];
            cnt++;
        }
    }

    cout<<ans<<"\n";
    return 0;
}
