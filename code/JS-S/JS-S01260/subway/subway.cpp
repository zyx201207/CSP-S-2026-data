#include<bits/stdc++.h>
using namespace std;
long long w[500005];
long long c,n,m,d,t;
vector<pair<int,long long>> arr[510005];
long long f(int x,int y){
    vector<long long> ar(n+m+15,0x3f3f3f3f3f3f3f3f);
    queue<pair<long long,int>> q;
    q.push({0,x});
    ar[x]=0;
    while(q.size()){
        int u=q.front().second;
        q.pop();
        for(auto i:arr[u]){
            if(ar[i.first]>ar[u]+i.second){
                ar[i.first]=ar[u]+i.second;
                q.push({ar[i.first],i.first});
            }
        }
    }
    return ar[y];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> t;
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    if(c>=1&&c<=6){
        vector<vector<long long>> ar(n+m+5,vector<long long>(n+m+5,0x3f3f3f3f3f3f3f3f));
        for(int i=1;i<=n;i++){
            long long k;
            cin >> k;
            for(int j=1;j<=k;j++){
                long long a,b;
                cin >> a >> b;
                ar[i][a+n]=ar[a+n][i]=b;
            }
        }
        for(int k=1;k<=n+m;k++){
            for(int i=1;i<=n+m;i++){
                for(int j=1;j<=n+m;j++){
                    ar[i][j]=ar[j][i]=min(ar[i][j],ar[i][k]+ar[j][k]);
                }
            }
        }
        while(t--){
            long long x,y;
            cin >> x >> y;
            cout << w[x]+w[y]+ar[n+x][n+y] << "\n";
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        long long k;
        cin >> k;
        cout << i << ":" << k << "\n";
        for(int j=1;j<=k;j++){
            long long a,b;
            cin >> a >> b;
            arr[i].push_back({a+n,b});
            arr[a+n].push_back({i,b});
        }
    }
    while(t--){
        long long x,y;
        cin >> x >> y;
        cout << w[x]+w[y]+f(n+x,n+y) << "\n";
    }
    return 0;
}
