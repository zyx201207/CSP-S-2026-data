#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e6+10;
int c,t,n,d,L,R;
int a[MAXN];
int l[MAXN],r[MAXN];
int tol[MAXN],tor[MAXN];
vector<int> lv,rv;
int dis[MAXN],cc[MAXN];
int solve1(){
    int ans=0;
    for(int i=1;i<=n;i++){
        tol[i]=0;
        tor[i]=n+1;
    }
    for(int i=1;i<=n;i++){
        tol[r[i]]=max(tol[r[i]],i);
        tor[l[i]]=min(tor[l[i]],i);
    }
    L=R=0;
    while(R+1<=n){
        lv.clear();
        rv.clear();
        L=R+1;
        R=L;
        while(R+1<=n&&a[R+1]-a[R]<=d)R++;
        for(int i=L;i<R;i++)
            if(tor[i]>i+1&&tol[i+1]<i&&tol[i+1]>=1&&tor[i]<=n){
                lv.push_back(tol[i+1]);
                rv.push_back(tor[i]);
                //cout<<l[i+1]<<" "<<r[i] <<' '<<tol[i+1]<<' '<<tor[i]<<'\n';
            }
        for(int i=0;i<(int)lv.size();i++){
            int ta,tb;
            if(i==0)ta=lv[i]-L+1;
            else ta=lv[i]-lv[i-1];
            if(i==(int)lv.size()-1)tb=R-rv[i]+1;
            else tb=rv[i+1]-rv[i];
            ans+=ta*tb;
        }
    }
    return ans;
}
int solve2(){
    int ans=0;
    for(int i=1;i<=n;i++){
        dis[i]=0;
        cc[i]=1;
        for(int j=i+1;j<=n;j++){
            dis[j]=MAXN;
            cc[j]=0;
        }
        for(int j=i+1;j<=n;j++){
            for(int k=max(i,l[j]);k<j;k++){
                if(dis[k]+1<dis[j]){
                    dis[j]=dis[k]+1;
                    cc[j]=cc[k];
                }else if(dis[k]+1==dis[j]){
                    cc[j]+=cc[k];
                }
            }
            if(cc[j]==2)ans++;
        }
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++){
            r[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
            l[i]=lower_bound(a+1,a+1+n,a[i]-d)-a;
        }
        if(n<=500)cout<<solve2()<<'\n';
        else cout<<solve1()<<'\n';
    }
    return 0;
}
//g++ migrate.cpp -o migrate -std=c++14 -O2 -static -Wall -Wextra -Wshadow
//ulimit -v 1048576
//ulimit -s 1048576
//time ./migrate