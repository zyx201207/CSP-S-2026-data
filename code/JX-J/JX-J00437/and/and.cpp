#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],trie[N][2],cnt[N];
int idx;
void add(int x){
    int i=0,d=0,f=1;
    while(x){
        int t;
        if(x<(1<<(30-d))&&f){
            t=0;
        }
        else{
            f=0;
            t=x%2;
            x/=2;
        }
        if(trie[i][t]==0){
            trie[i][t]=++idx;
            cnt[idx]++;
            i=idx;
        }else{
            i=trie[i][t];
            cnt[i]++;
        }
        d++;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        add(a[i]);
    }
    int ans=0;
    int i=0,d=0;
    while(1){
        if(trie[i][1]&&cnt[trie[i][1]]>1){
            ans+=1<<(30-d);
            i=trie[i][1];
            d++;
        }else if(trie[i][0]&&cnt[trie[i][0]]>1){
            i=trie[i][0];
            d++;
        }else{
            break;
        }
        //cerr<<ans<<' '<<d<<' ';
    }
    cout<<ans;
    return 0;
}
