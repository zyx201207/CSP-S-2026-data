#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=5e5+5;

int n;
ll m,a[N];
ull cost[N];

void solve1(){
    for(int i=1;i<=n;i++){
        cost[i]=1ull*i*(i+1)/2;
    }
    int pos=upper_bound(cost+1,cost+1+n,m)-cost;
    cout<<pos<<"\n";
}

void solve2(ll d){
    for(int i=1;i<=n;i++){
        cost[i]=1ull*i*(i+1)/2*d;
    }
    int pos=upper_bound(cost+1,cost+1+n,m)-cost;
    cout<<pos<<"\n";
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);

    int flag=1;
    for(int i=1;i<=n;i++){
        if(a[i]!=i){
            flag=0;
            break;
        }
    }
    if(flag){
        solve1();
        return 0;
    }

    flag=1;
    ll d=a[2]-a[1];
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=d){
            flag=0;
            break;
        }
    }
    if(flag){
        solve2(d);
        return 0;
    }

    int ans=0;
    for(int i=2;i<=n;i++){
        int res=0;
        ll used=0,pos=a[i];
        for(int j=i-1;j>0;j--){
            if(used+pos-a[j]<=m){
                used+=pos-a[j];
                res++;
            }
            else{
                break;
            }
        }
        ans=max(ans,res);
    }
    ans++;
    cout<<ans<<"\n";

    return 0;
}

/*

g++ -o crystal crystal.cpp -std=c++14 -O2 -static

./crystal <crystal1.in >crystal1.out

diff crystal1.out crystal1.ans

*/