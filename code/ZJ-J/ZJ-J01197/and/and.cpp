#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll n,m,a[N],maxx=0,mx;
ll ejz[50]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
void dfs(ll sum,ll c,ll x){
    if(c==m){
        maxx=max(sum,maxx);
        return;
    }
    for(int i=x;i<=n;i++){
        dfs(sum&a[i],c+1,x+1);
    }
    return ;
}
void solve1(){
    for(int i=1;i<=n;i++){
        dfs(a[i],1,i+1);
    }
    cout<<maxx;
    return ;
}
ll solve2(){
    ll sum=a[1];
    for(int i=2;i<=n;i++){
        sum&=a[i];
    }
    return sum;
}
map<int,int> t;
ll tries(int x){
    ll sum;
    if(x==1) sum=a[2];
    else sum=a[1];
    for(int i=1;i<=n;i++){
        if(i==x) continue;
        sum&=a[i];
    }
    return sum;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        t[a[i]]++;
    }
    sort(a+1,a+n+1,greater<ll>());
    if(n<=20){
        solve1();
    }
    else if(n<=2000){
        if(m==1) cout<<a[1];
        else if(m==n){
            cout<<solve2();
        }else{
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i==j) continue;
                    else maxx=max(maxx,a[i]&a[j]);
                }
            }
            cout<<maxx;
        }
    }
    else{
        if(m==n) cout<<solve2();
        else if(m==n-1){
            for(int i=1;i<=n;i++){
                if(t[a[i]]>=2) continue;
                else maxx=max(maxx,tries(i));
            }
            cout<<maxx;
        }
        else if(mx<=4){
            if(m<=t[mx]) cout<<mx;
            if(m<=t[2]+t[3]){
               cout<<2;
            }else if(m>t[2]+t[3]+t[1]){
                cout<<0;
            }
            else cout<<1;
        }

    }
    return 0;
}
