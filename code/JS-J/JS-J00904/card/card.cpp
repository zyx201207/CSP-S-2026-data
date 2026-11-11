#include<bits/stdc++.h>
using namespace std;
queue<int> q;
bool f[200005];
int ans[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
///////////// I want to 4/5*AC.
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        q.push(x);
    }
    for(int i=1;i<=n;++i){
        queue<int> que=q;
        for(int j=1;j<i;++j){
            que.pop();
        }
        stack<int>stk;
        while(!que.empty()){
            int x=que.front();
            que.pop();
            if(!f[x]){
                f[x]=true;
                stk.push(x);
            }else{
                while(stk.top()!=x){
                    int z=stk.top();
                    f[z]=false;
                    stk.pop();
                }
            }
        }
        while(!stk.empty()){
            int x=stk.top();
            f[x]=false;
            ++ans[x];
            stk.pop();
        }
    }
    for(int i=1;i<=m;++i){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
