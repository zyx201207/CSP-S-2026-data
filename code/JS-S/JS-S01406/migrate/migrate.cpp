#include<bits/stdc++.h>
using namespace std;

int pos[2000005];
vector<int> g[2000005];
int ans;
int n,d;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t;
    cin >> c >> t;
    while(t--){
        ans=0;
        cin >> n >> d;
        for(int i=0;i<n;i++){
            cin >> pos[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(pos[j]-pos[i]<=d)g[i].push_back(j);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cur_num=0;
                for(int temp:g[i]){
                    if(temp<=j)cur_num++;
                }
                if(cur_num==1)ans++;
            }
        }
        cout << ans << '\n';
        for(int i=0;i<n;i++){
            g[i].clear();
        }
        ans=0;
    }
    return 0;
}
