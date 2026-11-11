#include<bits/stdc++.h>
using namespace std;
long long mx=0;
int n,m;
void dfs(long long idx,long long ts,long long s,vector<long long>&p,vector<long long>&t){
    if(n-idx+1==m-ts){
        if(s!=-1)s&=t[idx];
        else s=t[idx];
        mx=max(mx,s);
        return;
    }
    if(ts==m){
        mx=max(s,mx);
        return;
    }
    if(s==-1){
        dfs(idx+1,ts+1,p[idx],p,t);
        dfs(idx+1,ts,s,p,t);
    }else{
        if(s<mx){
            return;
        }
        dfs(idx+1,ts+1,s&p[idx],p,t);
        dfs(idx+1,ts,s,p,t);
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    vector<long long>p(n+5);
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    vector<long long>t(n+5);
    t[n]=p[n];
    for(int i=n-1;i>=1;i--){
        t[i]=t[i+1]&p[i];
    }
    dfs(1,0,-1,p,t);
    cout<<mx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
