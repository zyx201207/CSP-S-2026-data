#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200010],b[300010],ans[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        int k = 1;
        for(int j = i;j<=n;j++){
            b[k] = a[j];
            for(int c = 1;c<=k;c++){
                if(b[k] == b[c]){
                    k = c;

                    break;
                }
            }

            k++;
        }
        for(int j = 1;j<k;j++){
            ans[b[j]] ++;
        }
    }
    for(int i = 1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
