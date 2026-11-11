#include <bits/stdc++.h>
using namespace std;
#define int long long
int b[1000005];
int n,m;
map<int,int>mp;stack<int>q;
set<int>s;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=max(1ll,i);j<=n;j++){
            if(s.find(b[j])!=s.end()){
                while(q.top()!=b[j]){
                    q.pop();
                }
            }
            else{
                q.push(b[j]);
                s.insert(b[j]);
            }
        }
        while(!q.empty()){
            mp[q.top()]++;
            q.pop();
        }
        s.clear();
    }
    for(int i=1;i<=m;i++){
        cout<<mp[i]<<' ';
    }
    return 0;
}
