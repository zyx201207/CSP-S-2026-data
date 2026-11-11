#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005], ans[100005];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        int v[100005]={0}, l[100005]={0};
        for(int j=i; j<=n; j++){
            if(v[a[j]]){
                for(int k=l[a[j]]; k<j; k++){
                    v[a[k]]=0;
                }
            }
            v[a[j]]=1;
            l[a[j]]=j;
        }
        for(int j=1; j<=m; j++){
            if(v[j]==1){
                ans[j]++;
            }
        }
    }
    for(int i=1; i<=m; i++){
        cout << ans[i] << " ";
    }
    return 0;
}