#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;
ll c,n,m,d,q,station_to_wait[500005],ans;
unordered_map<int,unordered_map<int,int>> line_to_wait,wait_to_line;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>station_to_wait[i];
    }
    for(int i=1;i<=n;i++){
        int k,st[k],tm[k];
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>st[j]>>tm[j];
            line_to_wait[i][st[j]=tm[j];
            wait_to_line[st[j][i]=tm[j];
        }
    }
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        ans=INT_MAX;
        for(int j=0;j<wait_to_line[x].size();j++){
            if(line_to_wait[wait_to_line[x][j]][y])ans=min(ans,station_to_wait[x]+wait_to_line[x][j]+line_to_wait[wait_to_line[x][j]][y]+station_to_wait[y]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
