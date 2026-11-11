#include<bits/stdc++.h>
using namespace std;
using in=long long;
in a[500005]={},b[300005]={};
in f[300005]={};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    in n,m;
    cin>>n>>m;
    stack<int>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(f,0,sizeof f);
        for(int j=i;j<=n;j++){
            if(f[a[j]]){
                while(q.top()!=a[j]){f[q.top()]=0;q.pop();}
                q.pop();
                q.push(a[j]);
            }
            else{
                f[a[j]]=1;
                q.push(a[j]);
            }
        }
        while(!q.empty()){
            b[q.top()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<' ';
    }
}
