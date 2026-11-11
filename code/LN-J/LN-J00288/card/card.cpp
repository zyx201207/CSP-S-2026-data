#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,NN=3e3+10;
int a[N];
int n,m;
stack<int> q;
int ans[NN],tong[NN];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(tong,0,sizeof(tong));
        for(int j=i;j<=n;j++){
            q.push(a[j]);
            if(tong[a[j]]==0)tong[a[j]]=1;
            else{
                q.pop();
                while(!q.empty()){
                    if(a[j]==q.top())break;
                    int k=q.top();
                    tong[k]=0;
                    q.pop();
                }
            }
        }
        while(!q.empty()){
            int k=q.top();
            ans[k]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
