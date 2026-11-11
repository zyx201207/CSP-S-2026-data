#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;

int n,m;
int a[N];
bool vis[M];
int dis[M];
int t[M];
stack <int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        memset(t,0,sizeof(t));
        int now=0;
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                while(!s.empty()){
                    int x=s.top();
                    s.pop();
                    if(x==a[j]) break;
                }
            }
            s.push(a[j]);
            vis[a[j]]=1;
        }
        while(!s.empty()){
            int x=s.top();
            s.pop();
            if(!t[x]){
                dis[x]++;
                t[x]=1;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<dis[i]<<" ";
    }
    return 0;
}
