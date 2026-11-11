#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int m,n;
int a[N],cnt[M],ans[M];
void game(int x){
    memset(cnt,0,sizeof(cnt));
    for(int i=x; i<=n; i++){
        cnt[a[i]]++;
        if(cnt[a[i]]>1){
            for(int j=x; j<i; j++){
                cnt[a[j]]--;
            }
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    for(int i=1; i<=n; i++){
        game(i);
        for(int j=1; j<=m; j++){
            if(cnt[j]) ans[j]++;
        }
    }
    for(int i=1; i<=m; i++) cout<<ans[i]<<' ';
    return 0;
}
