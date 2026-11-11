#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005],ans[3005];
vector<int> v;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }

    for(int i = 1;i<=n;i++){
        v.clear();
        for(int j = i;j<=n;j++){
            for(int k = 0;k<v.size();k++){
                if(v[k]==a[j]){
                    v.erase(v.begin()+k,v.end());
                    break;
                }
            }
            v.push_back(a[j]);
        }
        for(int k = 0;k<v.size();k++){
            ans[v[k]]++;
        }
    }

    for(int i = 1;i<=m;i++)cout<<ans[i]<<" ";

    return 0;
}
