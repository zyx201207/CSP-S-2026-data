#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N=5e5+2 ;
ll n,m,a[N],cnt[N],mw[N];
bool vis[N];
// 5e5*25 B
// 1250 KB
stack<int> table ;
void clean(int n){
    while(!table.empty()){
        if(table.top()==n){
            vis[table.top()]=0 ;
            table.pop() ;
            break ;
        }
        vis[table.top()]=0 ;
        table.pop() ;
    }
}
int main(){
    freopen("card.in","r",stdin) ;
    freopen("card.out","w",stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(0);cout.tie(0);
    cin >> n >> m ;
    for(int i=1;i<=n;i++){
        cin >> a[i] ;
        mw[a[i]]=i ;
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis)) ;
        for(int j=mw[a[i]];j<=n;j++){
            if(vis[a[j]]){
                clean(a[j]) ;
                table.push(a[j]) ;
                vis[a[j]]=1 ;
            }
            else{
                table.push(a[j]) ;
                vis[a[j]]=1 ;
            }
        }
        while(!table.empty()){
            cnt[table.top()]++ ;
            table.pop() ;
        }
    }
    for(int i=1;i<=m;i++) cout << cnt[i] << ' ' ;
    return 0 ;
}
