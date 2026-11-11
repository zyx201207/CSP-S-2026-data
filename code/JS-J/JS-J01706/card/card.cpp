#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        stack<int> stk;
        set<int> s;
        for(int j=i;j<=n;j++){
            if(s.find(a[j])!=s.end()){
                while(stk.top()!=a[j]){
                    s.erase(stk.top());
                    stk.pop();
                }
                s.erase(stk.top());
                stk.pop();
            }
            stk.push(a[j]);
            s.insert(a[j]);
        }
        while(!stk.empty()){
            ans[stk.top()]++;
            stk.pop();
        }
        
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }

    return 0;
}