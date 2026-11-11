#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
const int maxm=3e5+5;
int n,m;
int a[maxn];
bool vis[maxm]={0};
deque<int> q;
int st[maxn]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(vis[a[j]]==1){
                while(!q.empty()){
                    int t=q.back();
                    q.pop_back();
                    if(t==a[j]){
                        //cout<<i<<" "<<j<<endl;
                        break;
                    }
                }
            }
            vis[a[j]]=1;
            q.push_back(a[j]);
        }
        while(!q.empty()){
            int t=q.front();
            //cout<<t<<" ";
            st[t]++;
            q.pop_front();
        }
        q.clear();
        memset(vis,0,sizeof(vis));
        //cout<<endl;
    }

    for(int i=1;i<=m;i++){
        cout<<st[i]<<" ";
    }
    return 0;
}
