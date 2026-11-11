#include<bits/stdc++.h>
using namespace std;
long long n,m,aa[500005];
long long ans[300005];
long long match[500005],cnt=0;
long long card[500005];
void game(int p){
    cnt=0;
    memset(card,0,sizeof(card));
    memset(match,0,sizeof(match));
    for(int i=p;i<=n;i++){
        int num=aa[i];
        if(card[num]==0){
            cnt++;
            card[num]=cnt;
            match[cnt]=num;
        }else{
            for(int i=card[num]+1;i<=cnt;i++) match[i]=0;
            cnt=card[num];
            for(int i=1;i<=m;i++){
                if(card[i]>cnt) card[i]=0;
            }
        }
    }
    for(int i=1;i<=cnt;i++){
        ans[match[i]]++;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>aa[i];
    for(int i=1;i<=n;i++){
        game(i);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
