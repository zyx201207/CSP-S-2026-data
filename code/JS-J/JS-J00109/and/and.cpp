#include <bits/stdc++.h>
using namespace std;
bool a[200005],b[200005];
int ans[10],vis[2005],sum1[10000005],n,k,an;
long long cnt;
struct thing{
    int a;
    int b;
};
thing sum[10000005];
int my_pow(int x,int y){
    int dan;
    while (y != 0){
        if(y % 2 == 1){
            dan = dan * x;
        }
        y / 2;
        x =x * x;
    }
    return dan;
}
void bfs(int x){
    int cnt = 0;
    if(x == 3){
        cnt++;
        sum[cnt].a = ans[1];
        sum[cnt].b = ans[2];
    }
    for(int i = 1;i <= n;i++){
        if(vis[i] != 1){
            vis[i] = 1;
            ans[x] = a[i];
            bfs(x + 1);
            vis[i] = 0;
        }
    }
}
int apt(int h,int l){
    int i = 0;
    while(h != 0){
        if(h % 2 == 1){
            a[i] = 1;
        }
        i++;
        h /= 2;
    }
    int j = 0;
    while(l != 0){
        if(l % 2 == 1){
            b[j] = 1;
        }
        j++;
        l /= 2;
    }
    int tmp,da,m;
    for(int z = 0;z <= max(i,j);z++){
        if(a[z] == 1 && b[z] == 1){
            sum1[z] =1;
        }
        if(sum1[z] == 1){
            tmp = my_pow(2,m);
            da += tmp;
        }
        m++;
    }
    return da;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    bfs(1);
    for(int i = 1;i <= cnt;i++){
        int t = apt(sum[i].a,sum[i].b);
        an = max(an,t);
    }
    cout << an;
    return 0;
}
