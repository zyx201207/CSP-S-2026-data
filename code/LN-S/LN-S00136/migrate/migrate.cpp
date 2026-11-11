#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node{
    int minn,num;
}dis[6000];
int c,t,n,d,a[3000000],k;

void dfs(int s,int l){
    if(s==n) return;
    for(int i=s+1;i<=n;i++){
        if(a[i]-a[s]<=d){
            dfs(i,l+1);
            if(dis[i].minn==0||dis[i].minn>l+1){
                dis[i]={l+1,1};
            }else if(dis[i].minn==l+1) {dis[i].num++;}
        }else{break;}
    }
}

signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin >> c >> t;
while(t--){
    cin >> n >> d;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(n<=3){
        cout << "0" << endl;
        continue;
    }
    if(n<=300){
        int ans=0;
        for(k=1;k<=n-2;k++){
            memset(dis,0,sizeof(dis));
            dfs(k,1);
            for(int i=1;i<=n;i++){
                if(dis[i].num==2) ans++;
            }
        }cout << ans << endl;
    }
    if(c==11||c==12){
        k=a[2]-a[1];
    }
}

    return 0;
}
