 #include<bits/stdc++.h>
using namespace std;
int n,m,vis[200010];
long long a[200010],ans,cnt;
void diguei(int i,int s,long long cut){
    if(i>m){
        ans=max(ans,cut);
        return;

    }
    for(int j=s+1;j<=n-m+i;j++){
        diguei(i+1,j,cut&a[j]);
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cnt=a[i];
        memset(vis,1,sizeof(vis));
        diguei(2,i,cnt);
    }
    cout<<ans;
}
