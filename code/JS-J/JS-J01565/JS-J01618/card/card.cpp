#include<bits/stdc++.h>
using namespace std;
int ans[300005];
vector<int> csh,a;
int n,m,t;
void erase(int x){
    for(int i=0;i<a.size();i++){
        if(a[i]==x){
            a.erase(a.begin()+i,a.end());
            break;
        }
    }
    a.push_back(x);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>t;
        csh.push_back(t);
    }
    for(int k=1;k<=n;k++){
        a.clear();

        for(int i=0;i<csh.size();i++){
            erase(csh[i]);
        }
        for(auto i:a){
            ans[i]++;
        }
        csh.erase(csh.begin());
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
