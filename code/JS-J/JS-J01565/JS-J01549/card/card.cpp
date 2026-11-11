#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int p[300005];
stack<int> t;
map<int,int> mp;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        mp.clear();
        for(int j=i;j<=n;j++){
            if(mp[a[j]]==1){
                while(t.top()!=a[j]){
                    mp[t.top()]--;
                    t.pop();
                }
            }else mp[a[j]]++,t.push(a[j]);
        }while(!t.empty()){
            p[t.top()]++;
            t.pop();
        }
    }for(int i=1;i<=m;i++) cout<<p[i]<<" ";
    return 0;
}
