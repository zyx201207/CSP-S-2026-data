#include<bits/stdc++.h>
using namespace std;
//100 pts
int n,m,a[200003],vis[200003],ans=0x7fffffff,b[100],pre[100];
int w(int d){
    int cnt=0;
    while(d!=0){
        cnt++;
        if(d%2==1)b[cnt]++;
        d>>=1;
    }
    return cnt;
}
bool cmp(int a,int b){
    return a>b;
}
/*
void dfs(int cnt,int an){
    if(cnt==m){
        ans=max(ans,an);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==1)continue;
        vis[i]=1;
        dfs(cnt+1,an&a[i]);
        vis[i]=0;
    }
}
*/
int main(){
    //add
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);


    //delete


    cin >> n >> m;
    int maxw=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        int o=w(a[i]);
        maxw=max(maxw,o);
    }
    int pos=0;
    for(int i=maxw;i>0;i--){
        if(b[i]>=m){
            pos=i;
            break;
        }
    }
    pos=pow(2,pos)-1;
    for(int i=1;i<=n;i++){
        a[i]&=pos;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=m;i++){
        ans&=a[i];
    }
    /*
    if(m==n){
        for(int i=1;i<=n;i++){
            ans&a[i];
        }
        cout << ans;
        return 0;
    }
    dfs(0,0x7fffffff);
    */
    cout << ans;
    return 0;
}
