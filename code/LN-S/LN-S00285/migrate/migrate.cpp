#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;
int c,t,n;
ll d,x[N];
int cnt=0;
int find(int st){
    int tt=upper_bound(x+st,x+n+1,x[st]+d)-x-1;
    if(tt==st)return -1;
    else return tt;
}
int getmin(int s,int t){
    int res=0;
    if(find(s)==-1)return -1;
    int cur=s;
    while(cur!=t){
        int r=min(t,find(cur));
        if(r==-1)return -1;
        cur=r;
        res++;
    }
    return res;
}
bool dfs(int cur,int depth,int t,int mxd){
    if(depth>mxd || (depth==mxd && cur!=t))return false;
    else if(depth==mxd && cur==t){
        cnt++;
        if(cnt>2)return true;
    }else{
        int f=find(cur);
        if(find(cur)==-1)return false;
        for(int i=min(f,t);i>=cur+1;i--){
            if(dfs(i,depth+1,t,mxd))return true;
        }
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> t;
    if(0<=c && c<=10){
        while(t--){
            cin >> n >> d;
            for(int i=1;i<=n;i++)cin >> x[i];
            int ans=0;
            for(int a=1;a<=n-1;a++){
                for(int b=a+1;b<=n;b++){
                    cnt=0;
                    int mn=getmin(a,b);
                    if(mn==-1)continue;
                    dfs(a,0,b,mn);
                    if(cnt==2)ans++;
                }
            }
            cout << ans << '\n';
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}