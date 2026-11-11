#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--){
        int n,d;
        cin >> n >> d;
        vector<int> a(n);
        for(int i = 0;i<n;i++){
            cin >> a[i];
        }
        vector<vector<int>> adj(n,vector<int>(n,INT_MAX));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(abs(a[j]-a[i])<=d){
                    adj[i][j] = 1;
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int k = i;k<n;k++){
                if(adj[i][k] == INT_MAX)continue;
                for(int j = i;j<n;j++){
                    if(adj[k][j] == INT_MAX)continue;
                    adj[i][j] = min(adj[i][k]+adj[k][j],adj[i][j]);
                }
            }
        }
        int res = 0;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(adj[i][j]==1)continue;
                int count = 0;
                for(int k = i+1;k<j;k++){
                    if(adj[i][j] == adj[i][k]+adj[k][j]){
                        count++;
                    }
                }
                if(count==2)res++;
            }
        }
        cout << res << "\n";
    }

}
