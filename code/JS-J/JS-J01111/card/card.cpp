#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
map<int,int> mp;
stack<int> s;
map<int,int> ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int game=1;game<=n;game++){
        for(int i=game;i<=n;i++){
            if(mp[a[i]]==1){
                while(s.top()!=a[i]){
                    mp[s.top()]--;
                    s.pop();
                }
            }
            else{
                mp[a[i]]++;
                s.push(a[i]);
            }
        }
        while(s.size()){
            ans[s.top()]++;
            mp[s.top()]--;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
