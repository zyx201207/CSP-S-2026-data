#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,num;
};
queue<node>q;
queue<node>q1;
stack<int>s;
long long ans[300005];
bool ch[300005];
int n,m;
int k=1;
void f(int i){
    k++;
    node x=q.front();
    while(!q.empty()){
        if(k>=i)q1.push(x);
        q.pop();
        if(ch[x.a]==1){
            int y=s.top();
            while(y!=x.a){
                y=s.top();
                s.pop();
                ans[y]--;
                ch[y]=0;
            }
            ans[y]--;
            s.pop();
        }
        ch[x.a]==1;
        s.push(x.a);
        x=q.front();
    }
    while(!s.empty()){
        ch[s.top()]=0;
        s.pop();
    }
    while(!q1.empty()){
        node x=q1.top();
        q.push(x);
        q1.pop();
    }
}
int main(){
    cin>>n>>m;
    int a;
    for(int i=1;i<=n;i++){
        cin>>a;
        q.push({a,1});
        ans[a]+=n;
    }
    for(int i=n;i>=1;i--){
        f(i);
    }
    for(int i=1;i<=m;i++)cout<<ans[m];
    return 0;
}
