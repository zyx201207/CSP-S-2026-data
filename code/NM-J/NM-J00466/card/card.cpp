#include<bits/stdc++.h>
using namespace std;
int n,m,x;
bool a[300010]={0};
int b[300010]={0};
int r[500010];
queue<int>p;
stack<int>q;
stack<int>z;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>r[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            p.push(r[j]);
        }
        while(!p.empty()){
            if(a[p.front()]){
                while(q.top()!=p.front()){
                    q.pop();
                }
                q.pop();
            }
            q.push(p.front());
            a[p.front()]=1;
            p.pop();
        }
        for(int i=1;i<=m;++i){
            b[i]+=a[i];
            a[i]=0;
        }
    }
    for(int i=1;i<=m;++i){
        cout<<b[i]<<" ";
    }
    return 0;
}
