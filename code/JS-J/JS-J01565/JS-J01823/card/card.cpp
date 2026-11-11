#include<bits/stdc++.h>
using namespace std;
int c[500005],cid[300005],pl[500005],ans[300005],n,m;
int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> c[i];
    }
    for(int i = 1 ; i <= n ; i++){
        int b=0;
        for(int j = i ; j <= n ; j++){
            if(pl[ cid[ c[j] ] ] != c[j] || cid[ c[j] ] > b){
                b++;
                pl[b]=c[j];
                cid[ c[j] ]=b;
            }else{
                b=cid[c[j]];
            }
        }
        for(int j = 1 ; j <= b ; j++){
            ans[ pl[j] ]++;
        }
        memset(cid,0,sizeof(cid));
    }
    int tmp;
    for(int i = 1 ; i <= m ; i++){
        cout << ans[i] << " ";
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
