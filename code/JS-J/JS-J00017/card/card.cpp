#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
vector <int> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        v.clear();
        for(int j=i;j<n;j++){
            if(v.empty()) v.push_back(a[j]);
            else{
                for(int k=0;k<v.size();k++){
                    if(v[k]==a[j]){
                        v.erase(v.begin(),v.begin()+k+2);
                        break;
                    }
                }
                v.push_back(a[j]);
            }
        }
        for(int j=0;j<v.size();j++) ans[v[j]]++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
