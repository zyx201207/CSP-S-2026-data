#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int ans[300010];
void solve(int x){
    stack<int> s;
    int r[300010] = {0};
    bool ra[300010] = {0};
    for(int i = x;i<=n;i++){
        if(r[a[i]]){
            while(s.top()!=a[i]){
                    r[s.top()]--;
                s.pop();
            }
            r[s.top()]--;
            s.pop();
        }
        s.push(a[i]);
        r[a[i]]++;
    }
    while(s.size()!=0){
        ra[s.top()] = 1;
        s.pop();
    }
    for(int i = 0;i<=m;i++){
        if(ra[i]==1){
            ans[i]++;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 0;i<n;i++){
        solve(i+1);
    }
    for(int i = 1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
