#include<bits/stdc++.h>
using namespace std;
int bt[35],a[200005];

bool book[200005];
int n,m;
int maxn=-1;
void dfs(int p,int jg,int mj){
    if(p>m){
        maxn=max(jg,maxn);
        return;
    }
    for(int i=mj;i<=n;i++){
        if(book[i]==0){
            book[i]=1;
            int x;
            if(p==1){
                x=a[i];
            }
            else{
                x=a[i]&jg;
            }
            dfs(p+1,x,i+1);
            book[i]=0;

        }
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,1);
    cout<<maxn;
    return 0;
}
