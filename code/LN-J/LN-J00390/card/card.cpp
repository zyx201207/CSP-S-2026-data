#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,a[N],ans[N],v[M],m;
stack<int>s;
void dfs(int t){
    for(int i=t;i<=n;i++){
        if(v[a[i]]==0){
            v[a[i]]=1;
            s.push(a[i]);
        }
        else{
            while(s.top()!=a[i]){
                v[s.top()]=0;
                s.pop();
            }
        }
    }
    while(!s.empty()){
        ans[s.top()]++;
        s.pop();
    }
    return;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(v,0,sizeof(v));
        dfs(i);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
