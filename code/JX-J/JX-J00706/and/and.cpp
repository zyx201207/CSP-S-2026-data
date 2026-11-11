#include<bits/stdc++.h>
using namespace std;
int a[200005];
int a2[200005];
bool a1[200005];
int n,m;
long long ans,cnt;
void dfs(int d,int x){
    if(d>m){
        ans=max(ans,cnt);
        return;
    }
    if(d==2){
        cnt=a[x];
    }
    for(int i=x;i<=n;i++){
        if(!a1[i]){
            a1[i]=1;
            a2[x]=cnt;
            cnt&=a[i];
            dfs(d+1,i);
            cnt=a2[x];
            a2[x]=0;
            a1[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,1);
    cout<<ans;
    return 0;
}
