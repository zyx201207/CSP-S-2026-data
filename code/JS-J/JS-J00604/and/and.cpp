#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a,ans=0,cnt=0;
vector<int>tt;
void dfs(int now,int pl,int num){
    cnt++;
    if(n-pl+num<m)return;
    if(num==m){ans=max(ans,now);return;}
    for(int i=pl+1;i<n;i++){
        dfs(now&tt[i],i,num+1);
    }
    if(cnt>3e8){
        cout <<ans;
        exit(0);
    }
    return;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >>n>>m;
    for(int i=0;i<n;i++){
        cin >>a;
        tt.push_back(a);
    }
    for(int i=0;i<n-m;i++){
        dfs(tt[i],i,1);
    }
    cout <<ans;
    return 0;
}
