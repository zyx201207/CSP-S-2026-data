#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,m,a[N],cnt[N],ans[N];
struct nod{
    int x = 0,y = 0;
}pos[300010];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(pos[a[i]].x){
            pos[a[i]].y = i;
        }else {
            pos[a[i]].x = i;
        }
    }
    for(int i = n;i <= 1;i--){
        memset(cnt,1,sizeof(cnt));
        for(int j = 1;j <= i;j++){
            if(pos[a[j]].y <= i&&pos[a[j]].y != 0){
                for(int l = pos[a[j]].x;l <= pos[a[j]].y;l++)
                    cnt[l] = 0;
            }
        }
        for(int j = 1;j <= i;j++){
            if(cnt[j])ans[a[j]]++;
        }
    }
    for(int i = 1;i <= m;i++)cout << ans[a[i]] << ' ';
    return 0;
}