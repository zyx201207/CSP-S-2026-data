#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=5e5+5;
int c,T,n,d,x[N];
void qrw(){
    ios::sync_with_stdio(0);
    cin.tie(0);
}
int a[15],ans=0,ok=0,minn,idx;
bool check(int st,int ed){
    int cnt=0,lst=0;
    x[0]=LLONG_MAX/4;
    for(int i=st;i<=ed;i++){
        if(a[i]){
            cnt++;
            if(x[i]-x[lst]>d){
                return 0;
            }
            lst=i;
        }
    }
    if(cnt-1==minn){
        //cout<<"OOPS";
        return 1;
    }else{
        return 0;
    }
}
void dfs(int step,int type,int st,int ed){
    a[step]=type;
    if(step==ed&&a[step]==1){
        if(check(st,ed)) ok++;
        return;
    }
    dfs(step+1,0,st,ed);
    dfs(step+1,1,st,ed);
}
void solve(){
    cin>>n>>d;
    ans=0;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<n;i++){
        minn=0,idx=i;
        for(int j=i+1;j<=n;j++){
            ok=0;
            if(x[j]-x[idx]>d){
                if(j==idx+1){
                    break;
                }
                minn++;
                idx=i-1;
            }
            if(minn){
                dfs(i,1,i,j);
                if(ok==2){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    qrw();
    cin>>c>>T;
    while(T--){
        solve();
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/