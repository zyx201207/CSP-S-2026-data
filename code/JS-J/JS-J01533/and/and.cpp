#include<bits/stdc++.h>
using namespace std;
#define db double
#define ldb long double
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int,int>
#define pdi pair<double,int>
#define pid pair<int,double>
#define fi first
#define se second
#define fp(x) fixed<<setprecision(x)
#define lb lower_bound
#define ub upper_bound
#define lowbit(x) (x)&(-x)
#define pb push_back
#define pf push_front
#define ep emplace
#define eb emplace_back
#define mpr make_pair
int T=1,n,m,a[200010],ans,t[40];
//int wzc=-1000000000000000000;
bool flag=1;
vector<int>num[200010];
bool cmp(int x,int y){
    return x>y;
}
bool check(int k){
    if((k&(k+1))==0){
        return 1;
    }return 0;
}
void solve(){
    cin>>n>>m;
    rep(i,1,n){
        cin>>a[i];
        if(!check(a[i])){
            flag=0;
        }
    }
    sort(a+1,a+1+n,cmp);
    if(flag){//13
        ans=(1<<30)-1;
        rep(i,1,m){
            ans=(ans&a[i]);
        }
        cout<<ans;
        return;
    }
    if(a[1]<=3){//16~17
        rep(i,1,n){
            t[a[i]]++;
        }
        if(t[3]>=m){
            cout<<3;
            return;
        }
        if(t[3]<m&&t[3]+t[2]>=m){
            cout<<2;
            return;
        }
        if(t[3]<m&&t[3]+t[2]<m&&t[3]+t[1]>m){
            cout<<1;
            return;
        }cout<<0;
        return;
    }
    if(n<=20){//1~5
        ans=(1<<30)-1;
        rep(i,1,m){
            ans=(ans&a[i]);
        }
        cout<<ans;
        return;
    }
    if(m==1){//6
        cout<<a[1];
        return;
    }
    if(m==n){//7
        ans=(1<<30)-1;
        rep(i,1,n){
            ans=(ans&a[i]);
        }
        cout<<ans;
        return;
    }
    if(m==2){//8~10
        ans=-1000000000;
        rep(i,1,n){
            rep(j,i+1,n){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return;
    }
    if(m==n-1){//11~12
        ans=(1<<30)-1;
        rep(i,1,m){
            ans=(ans&a[i]);
        }
        cout<<ans;
        return;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //cin>>T;
    while(T--){
        solve();
    }
}
