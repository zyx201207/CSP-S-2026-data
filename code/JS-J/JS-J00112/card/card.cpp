#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int ans[M];
int f[N];
bool v[N];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, cnt=0;
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>f[i];
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            if(v[f[j]])v[f[j]]=0, cnt++;
            if(cnt==m) break;
        }
        int flag;
        for(int j=i; j<=n; j++){
            if(!v[f[j]]){
                v[f[j]]=1;
                ans[f[j]]++;
            }
            else {
                v[f[j]]=1;
                ans[f[j]]++;
                for(int k=j-1; k>=i; k--){
                    v[f[k]]=0;
                    ans[f[k]]--;
                }
            }
        }
    }
    for(int i=1; i<=m; i++) cout<<ans[i]<<' ';

    return 0;
}
