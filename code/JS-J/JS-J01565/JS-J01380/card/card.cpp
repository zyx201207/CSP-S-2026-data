#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 5e5 + 5;
const int maxm = 3e5 + 5;
int n, m;
int a[maxn];
int vis[maxm];
int gnum[maxn], gcnt;
int ans[maxm];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        gcnt = 0;
        for(int j = i; j <= n; j++){
            gcnt++;
            if(vis[a[j]] != 0){
                for(int k = gcnt - 1; k >= vis[a[j]] + 1; k--){
                    vis[gnum[k]] = 0;
                    gnum[k] = 0;
                }
                gcnt = vis[a[j]];
            }else{
                gnum[gcnt] = a[j];
                vis[gnum[gcnt]] = gcnt;
            }
        }
        //cout<<i<<" :: ";
        for(int j = 1; j <= gcnt; j++){
            //cout<<gnum[j]<<" ";
            ans[gnum[j]]++;
            vis[gnum[j]] = 0;
            gnum[j] = 0;
        }
        //cout<<endl;
    }
    for(int i = 1; i <= m; i++){
        cout << ans[i] << " ";
    }
    cout<<endl;

    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
