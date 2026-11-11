#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        vector<int> v;
        for(int j=i;j<=n;j++){
            for(int k=0;k<v.size();k++){
                if(k==a[j]){
                    v.erase(v.begin()+k-1,v.end());
                    break;
                }
            }
            v.push_back(a[j]);
        }
        for(int j=0;j<v.size();j++) ans[v[j]]++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
