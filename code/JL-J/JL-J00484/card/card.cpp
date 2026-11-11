#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[500010];
vector<int> v;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=0;k<v.size();k++){
                if(v[k]==a[j]){
                    v.erase(v.begin()+k,v.end());
                    break;
                }
            }
            v.push_back(a[j]);
        }
        for(int i=0;i<v.size();i++)
            ans[v[i]]++;
        v.clear();
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    return 0;
}
