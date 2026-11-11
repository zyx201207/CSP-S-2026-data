#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

int n;
struct node{
    int num;
    char c;
}a[N];
int len;
int vis[N];
int product;
bool pt;
int ans, id;

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i].num >> a[i].c;
    }
    id = n;
    for(int i = 1; i <= n && i != id; i ++){
        if(a[i].num < a[id].num){
            vis[id] ++;
            if(vis[i])
                break;
            if(a[i].c != a[id].c)
                ans += min(a[i].num, a[id].num);
            a[id].num -= a[i].num;
        }else if(a[i].num > a[id].num){
            while(a[i].num > a[id].num && i != id){
                vis[id] ++;
                if(vis[i])
                    break;
                if(a[i].c != a[id].c)
                    ans += min(a[i].num, a[id].num);
                a[i].num -= a[id].num;
                id --;
            }
            vis[id] ++;
            if(vis[i])
                break;
            if(a[i].num < a[id].num){
                if(a[i].c != a[id].c)
                    ans += min(a[i].num, a[id].num);
                a[id].num -= a[i].num;
            }
            else if(a[i].num == a[id].num){
                if(a[i].c != a[id].c)
                    ans += min(a[i].num, a[id].num);
                id--;
            }
        }else{
            vis[id] ++;
            if(vis[i])
                break;
            if(a[i].c != a[id].c)
                ans += min(a[i].num, a[id].num);
            id --;
        }
    }
    cout <<ans;
    return 0;
}
