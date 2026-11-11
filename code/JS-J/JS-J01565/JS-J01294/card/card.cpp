#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+5;
int a[N];
int ans[N];
bool vis[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=500){
        for(int i=1;i<=n;i++){
        stack<int> s;
        memset(vis,0,sizeof(vis));
        for(int j=i;j<=n;j++){
            if(!vis[a[j]]){
                vis[a[j]]=1;
                s.push(a[j]);
            }
            else{
                while(!s.empty()&&s.top()!=a[j]){vis[s.top()]=0;s.pop();}
            }
        }
        while(!s.empty()){
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    }
    for(int i=1;i<=n;i++){
        ans[1]++;
        ans[a[i]+1]--;
    }
    for(int i=1;i<=m;i++){
        ans[i]=ans[i-1]+ans[i];
        cout<<ans[i]<<" ";
    }
    return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/