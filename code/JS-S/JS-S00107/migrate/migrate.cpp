#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int c,t,cnt,n,mi;
typedef long long ll;
ll d,x[MAXN];
priority_queue<int,vector<int>,greater<int> > q;
void dfs(int l,int r,int ans){
    if(!q.empty()&&ans>q.top()) return;
    if(l==r){
        q.push(ans);
        return;
    }
    for(int i=l+1;x[i]-x[l]<=d&&i<=r;i++) dfs(i,r,ans+1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cnt=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                bool a=true;
                dfs(j,i,0);
                if(q.empty()) continue;
                mi=q.top();
                q.pop();
                if(q.empty()) continue;
                if(q.top()!=mi) a=false;
                q.pop();
                if(!q.empty()&&q.top()!=mi&&a==true) cnt++;
                while(!q.empty()) q.pop();
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
