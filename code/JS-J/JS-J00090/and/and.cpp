#include<bits/stdc++.h>
using namespace std;
vector<int>s[200005];
long long n,m,ans=0,op;
bool vis[200005];
long long solve(vector<int>x){
    long long cnt=0;
    for(int p=0;p<x.size();p++)cnt=cnt*2+x[p];
    return cnt;
}
void dp(vector<int>x,long long y,long long cnt){
    vis[y]=1;
    if(cnt+1==m){
        long long y=solve(x);
        ans=max(y,ans);
        vis[y]=0;
        return;
    }
    for(long long j=op+1;j<n;j++){
        if(vis[j]==1)continue;
        vector<int>g;
        if(s[j].size()>x.size()){
            int cs=s[j].size()-x.size();
            for(int k=0;k<x.size();k++){
                if(s[j][k+cs]==x[k] && x[k]==1)g.push_back(1);
                else g.push_back(0);
            }
        }else if(s[j].size()<x.size()){
            int cs=x.size()-s[j].size();
            for(int k=0;k<s[j].size();k++){
                if(s[j][k]==x[k+cs] && x[k+cs]==1)g.push_back(1);
                else g.push_back(0);
            }
        }else{
            for(int k=0;k<x.size();k++){
                if(s[j][k]==x[k])g.push_back(1);
                else g.push_back(0);
            }
        }
        reverse(g.begin(),g.end());
        dp(g,j,cnt+1);
    }
    vis[y]=0;
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++)vis[i]=0;
    for(long long i=0;i<n;i++){
        long long a;
        cin >> a;
        while(a){
            s[i].push_back(a%2);
            a/=2;
        }
        reverse(s[i].begin(),s[i].end());
    }
    for(long long i=0;i<n;i++){
        for(int j=0;j<n;j++)vis[i]=0;
        op=i;
        dp(s[i],i,0);
    }
    cout << ans;
}
//CSCCF Broken Computer
