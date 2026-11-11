#include <bits/stdc++.h>
using namespace std;
const int maxa=5*1e5+5;
int n,m;
int a[maxa],cnt[maxa];
queue<int> q;
bool wu(int k){
    for(int i=1;i<=n;i++){
        if(q.front()==k) return false;
        q.push(q.front());
        q.pop();
    }
    return true;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(wu(a[j])){
                q.push(a[j]);
            }
            else{
                int x=q.front();
                while(q.front()!=a[j]){
                    q.push(q.front());
                    q.pop();
                }
                q.push(q.front());
                q.pop();
                while(q.front()!=x){
                    q.pop();
                }
            }
        }
        while(!q.empty()){
            cnt[q.front()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
