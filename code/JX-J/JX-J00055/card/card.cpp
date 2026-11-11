#include<bits/stdc++.h>
using namespace std;
int m,n;
int z;
int a[500005];//dainshu
bool vis[500005];//biaojishuzu
int p[500005];//jieguo
void print(){
    for(int i = 1;i<=m;i++){
        if(vis[i]){
            p[i]++;
            vis[i] = 0;
        }
    }
    return;
}
void pl(int x){
    for(int i = x;i<=n;i++){
        int d = a[i];
        if(vis[d]){
            for(int j = i-1;j>=x;j--){
                vis[a[j]] = 0;
                if(a[j] == d){
                    break;
                }
            }
        }
        vis[d] = 1;
    }
    print();
    return;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    for(int i = 1;i<=n;i++){
    pl(i);
    }
    for(int i = 1;i<=m;i++){
        if(p[i]) cout << p[i] << " ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
