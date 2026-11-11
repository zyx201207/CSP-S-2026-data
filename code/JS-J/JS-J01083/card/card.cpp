#include <bits/stdc++.h>
using namespace std;

using ll=long long;
int n,m;
int a[500010];
int sear[500010],ans[300010];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++){
        int now=1;
        for(int j = i;j <= n;i++){
            for(int k = 1;k <= now;k++){
                if(sear[k]==a[j]){
                    now=k;
                    for(int z = k;z <= j;z++){
                        sear[z]=0;
                    }
                    break;
                }
            }
            sear[now]=a[j];
        }
        for(int j = 1;j <= now;j++){
            ans[sear[j]]++;
        }
    }
    for(int i = 1;i <= n;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
