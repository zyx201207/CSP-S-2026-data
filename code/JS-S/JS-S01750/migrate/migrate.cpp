#include<bits/stdc++.h>
using namespace std;
#define ll long long
//void int bool vector priority_queue pair<ll int>
int c,t,n,d,x[100010],ms = 555555,mscnt = 1,ans = 0,step2[500005];
void dfs(int b,int e,int step){
    if(b == e){
        if(step < ms){
            ms = step;
            mscnt=1;
        }else if(step == ms)mscnt++;
        return ;
    }
    if(step > step2[b])return;
    step2[b] = step;
    for(int i = b+1;i<=e;i++){
        if(x[b] + d >= x[i]){
            int step1 = step+1;
            dfs(i,e,step1);
        }else return;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> t;
    while(t--){
        ans = 0;
        cin >> n >> d;
        for(int i = 1;i<=n;i++)cin >> x[i];
        for(int i = 1;i<=n;i++)step2[i] = 500005;
        for(int l = 1;l<=n;l++){
            int r = l;
            while(r<n){
                r++;
                ms = 555555;mscnt = 1;
                dfs(l,r,0);
                if(mscnt == 2){
                        ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
