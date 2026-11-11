#include <bits/stdc++.h>
using namespace std;
long long a[200001];
long long ans[3001];
long long pos[3001];
void ep(int l,int r){
    for(int i = l;i <= r;i++){
        pos[a[i]] = 0;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        ep(1,m);
        int ni = i;
        for(int j = i;j <= n;j++){
            if(pos[a[j]] != 0 && pos[a[j]] <= ni){
                ni = pos[a[j]]+1;
                ep(j,ni);
                pos[a[j]] = ni -1;
            }else{
                pos[a[j]] = ni;
                ni++;
            }
        }
        for(int j = 1;j <= m;j++){
            if(pos[j]){
                ans[j] += 1;
            }
        }
    }
    for(int i = 1;i <= m;i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
