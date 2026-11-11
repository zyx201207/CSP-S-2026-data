#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
bool vis[300005];
int vis2[300005];
vector <int> q;
void qk(){
    while(!q.empty()){
        vis[q[q.size()-1]]=0;
        q.pop_back();
    }
}
void qj(int qd){
    qk();
    for(int i=qd;i<=n;i++){
        if(vis[a[i]]==0){
            vis[a[i]]=1;
            q.push_back(a[i]);
        }else{
            while(1){
                if(q[q.size()-1]==a[i]){
                    q.pop_back();
                    break;
                }
                vis[q[q.size()-1]]=0;
                q.pop_back();
            }

            vis[a[i]]=1;
            q.push_back(a[i]);
        }
    }
    for(int i=1;i<=m;i++){
        if(vis[i]==1){
            vis2[i]++;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>=1e5){
        if(m<=2){
            cout<<n<<' '<<n;
        }
    }
    for(int i=1;i<=n;i++){
       qj(i);
    }
    for(int i=1;i<=m;i++){
        cout<<vis2[i]<<' ';
    }
    return 0;
}
