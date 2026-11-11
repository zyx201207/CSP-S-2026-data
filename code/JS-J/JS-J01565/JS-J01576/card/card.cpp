#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005];
ll ans[500005];

ll table[500005];
ll table_len=0;
ll book[500005];
void solve(){
    for(int i=1;i<=n;i++){
        table_len=0;
        memset(table,0,sizeof(table));
        memset(book,0,sizeof(book));
        for(int j=i;j<=n;j++){
            if(!book[a[j]]){
                book[a[j]]=++table_len;
                table[table_len]=a[j];
            }else{
                if(table[book[a[j]]]!=a[j]||table_len<book[a[j]]){
                    book[a[j]]=++table_len;
                    table[table_len]=a[j];
                }else{
                    table_len=book[a[j]];
                }
            }
        }
        //cout<<i<<"\n";
        for(int j=1;j<=table_len;j++){
        //    cout<<table[j]<<" ";
            ans[table[j]]++;
        }
        //cout<<"\n";
    }
    return;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    solve();
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
// orz rp++ csp-j1= made by cici
// hope 50pts orz orz
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
