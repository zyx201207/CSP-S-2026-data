#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=2e5+5;
int n,m;
stack<int> s;
int a[N],vis[M];
int cnt[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            vis[j]=0;
        }
        while(!s.empty()){
            s.pop();
        }
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                while(1){
                    int x=s.top();
                    s.pop();
                    vis[x]=0;
                    if(x==a[j]){
                        s.push(a[j]);
                        vis[a[j]]=1;
                        break;
                    }
                }
                s.push(a[j]);
                vis[a[j]]=1;
            }
            s.push(a[j]);
            vis[a[j]]=1;
        }
        //cout<<11111<<endl;
        for(int j=1;j<=m;j++){
            if(vis[j]){
                //cout<<i<<":"<<j<<endl;
                cnt[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }

    return 0;
}
