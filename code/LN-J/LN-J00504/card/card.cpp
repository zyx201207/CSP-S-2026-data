#include<bits/stdc++.h>
using namespace std;
int a[500022];
queue<int> q;
queue<int> r;
int flag=0;
queue<int> g;
queue<int> t;
int appear[300022];
int ans[300022];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            while(!q.empty()){
                if(q.front()==a[j]){
                    flag=1;
                }
                r.push(q.front());
                q.pop();
            }
            while(!r.empty()){
                g.push(r.front());
                q.push(r.front());
                r.pop();
            }
            if(flag==0){
                q.push(a[j]);
            }
            else{
                while(q.front()!=a[j]){
                    q.pop();
                }
            }
            flag=0;
        }
        while(!q.empty()){
            appear[q.front()]++;
            q.pop();
        }
        for(int j=1;j<=m;j++){
            if(appear[j]!=0){
                ans[j]++;
            }
        }
        memset(appear,0,sizeof(appear));
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
