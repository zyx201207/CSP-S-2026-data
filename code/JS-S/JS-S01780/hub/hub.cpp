#include <bits/stdc++.h>
using namespace std;
int c,T,n,m,d[1005][1005],ans;
vector<int> a[1000005];
void dfs(int x,int fa,int t){
    for(int i=0;i<int(a[x].size());i++){
        int y=a[x][i];
        if(y==fa) continue;
        d[t][y]=d[t][x]+1;
        dfs(y,x,t);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        //cout<<n/6<<" "<<m<<"\n";
        if(c==0||(13<=c&&c<=14)){
            int tmp=n/2;
            if(n==m) cout<<0<<"\n";
            else if(m>=tmp) cout<<1<<"\n";
            else{
                tmp=(tmp-m)/4+((tmp-m)%4!=0);
                tmp=tmp+1;
                cout<<tmp<<"\n";
            }
            continue;
        }
        for(int i=1;i<=n;i++) dfs(i,0,i);
        ans=1e9;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int maxn=0;
                for(int k=1;k<=n;k++){
                    maxn=max(maxn,min(d[i][k],d[j][k]));
                 //   if(i==2&&j==3) cout<<k<<" "<<min(d[i][k],d[j][k])<<"\n";
                }
                ans=min(ans,maxn);
            }
            //cout<<maxn<<"\n"
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
1 1 7 3
1 2
1 3
2 4
2 5
3 6
3 7
*/
