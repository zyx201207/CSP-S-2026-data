#include<bits/stdc++.h>
using namespace std;
int m,n,x[500010];
long long y[200010];
bool vis[200010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    stack<int>a;
    for(int i=1;i<=n;i++)cin>>x[i];
    int b=1;
    while(b<=n){
        for(int i=1;i<=m;i++)vis[i]=false;
        for(int i=b;i<=n;i++){
            if(!vis[x[i]]){
                a.push(x[i]);
                vis[x[i]]=true;
            }
            else {
                while(a.top()!=x[i]){
                    vis[a.top()]=false;
                    a.pop();
                }
            }
        }
        while(!a.empty()){
            ++y[a.top()];
            cout<<a.top()<<" ";
            a.pop();
        }
        b++;
    }
    for(int i=1;i<=m;i++){
        cout<<y[i]<<" ";
    }
    return 0;
}
