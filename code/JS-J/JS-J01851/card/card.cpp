#include <bits/stdc++.h>
using namespace std;
vector<int> a(20000),table(20000),ans(3000);
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(find(table.begin(),table.end(),a[j])==table.end()){
                table.push_back(a[j]);
            }
            else{
                table.erase(find(table.begin(),table.end(),a[j]),table.end());
                table.push_back(a[j]);
            }
        }
        for(auto i:table){
            ans[i]++;
        }
    }
    for(int i=0;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}