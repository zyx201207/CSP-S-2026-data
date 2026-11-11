#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
const int MAXM=3e5+10;
int n,m,a[MAXN],dif[MAXN],ans[MAXM],w[MAXM],sum[MAXN][2];
bool vis[MAXM];
struct STACK{
    vector<int> val;
    void New(int x){
        val.push_back(x);
    }
    void pop(int x){
        while(val.size()&&val[val.size()-1]<x) val.pop_back();
    }
    int top(){
        return val[val.size()-1];
    }
    bool empty(){return val.size()==0;}
}S[MAXM];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if((n<=5000&&m<=3000)){
        vector<int> q;q.clear();
        for(int i=1;i<=n;i++){
            q.clear();
            for(int j=1;j<=m;j++) vis[j]=0;
            for(int j=i;j<=n;j++){
                if(vis[a[j]]) while(q.size()&&q[q.size()-1]!=a[j]) vis[q[q.size()-1]]=0,q.pop_back();
                else q.push_back(a[j]),vis[a[j]]=1;
            }
            for(int j:q) ans[j]++;
        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<" ";cout<<"\n";
        return 0;
    }
    for(int i=1;i<=n;i++) sum[i][0]=sum[i-1][0],sum[i][1]=sum[i-1][1],sum[i][a[i]-1]++;
    for(int i=1;i<=n;i++){
        int w=n+1;
        for(int j=n;j>=i;j--){
            if(sum[n][0]-sum[j-1][0]<=1&&sum[n][0]-sum[j-1][0]<=1) w=j;
            else break;
        }
        dif[w]++;
    }
    for(int i=1;i<=n;i++) dif[i]+=dif[i-1],ans[a[i]]+=dif[i];
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";cout<<"\n";
    return 0;
}