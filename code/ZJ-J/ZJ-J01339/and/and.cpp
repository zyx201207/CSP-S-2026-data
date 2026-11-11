#include<bits/stdc++.h>
const int N=2010;
using namespace std;
int num[N],n,m,cnt,maxx;
stack<int> q,s;
void dfs(int l,int sum){
    if(sum==m){
        int cnt=q.top();
        //cout<<q.top()<<" ";
        s.push(q.top());
        q.pop();
        while(q.size()){
            if(q.empty()) break;
            int f=q.top();
            //cout<<q.top()<<" ";
            s.push(q.top());
            cnt=(cnt&f);
            q.pop();
        }
        //cout<<cnt<<"\n";
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        maxx=max(maxx,cnt);
        return;
    }
    if(l>n) return;
    q.push(num[l]);
    dfs(l+1,sum+1);
    q.pop();
    dfs(l+1,sum);
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    if(n==m){
        cnt=num[1];
        for(int i=2;i<=n;i++){
            cnt&=num[i];
        }
        cout<<cnt;
    }else if(m==1){
        for(int i=1;i<=n;i++) maxx=max(maxx,num[i]);
        cout<<maxx;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                maxx=max(maxx,num[i]&num[j]);
            }
        }
        cout<<maxx;
    }else{
        dfs(1,0);
        cout<<maxx;
    }
    return 0;
}