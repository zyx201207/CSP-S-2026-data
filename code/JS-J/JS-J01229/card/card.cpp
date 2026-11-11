#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN = 5010;
ll n,m,cnt = 0;
ll a[MAXN];
ll st[MAXN];
ll vis[MAXN];
ll Hash[MAXN];
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("card.in",'r',stdin);
    freopen("card.out",'w',stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    for(int i = 1;i <= n;i++){
        cnt = 0;
        for(int i = 1;i <= n;i++) vis[i] = -1;
        for(int j = i;j <= n;j++){
            ++cnt;
            ll p = vis[a[j]];
            if(p == -1){
                st[cnt] = a[j];
                vis[a[j]] = cnt;
            }else{
                for(int k = p + 1;k < cnt;k++){
                    vis[st[k]] = -1;
                }
                cnt = p;
            }
        }
        for(int i = 1;i <= cnt;i++){
            Hash[st[i]]++;
        }
    }
    for(int i = 1;i <= m;i++){
        cout<<Hash[i]<<" ";
    }
    return 0;
}
