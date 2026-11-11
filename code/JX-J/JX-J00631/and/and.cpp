#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct A{
    ll a;
    bool e;
};
const int N=2e5+5;
A lst[N];
queue<ll> del;

int wei(ll a){
    int w=0;
    for( ; a; a>>=1) w++;
    return w;
}

bool read(ll a, int w){
    return (a>>(w-1))&1;
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m, ecnt;
    int wmax=0;
    ll ans=0;
    cin>>n>>m;
    ecnt=n;
    for(int i=1; i<=n; i++){
        cin>>lst[i].a;
        lst[i].e=1;
        wmax=max(wmax, wei(lst[i].a));
    }
    for(int w=wmax; w>=1; w--){
        ans<<=1;
        while(!del.empty()) del.pop();
        for(int i=1; i<=n; i++){
            if(!lst[i].e) continue;
            if(!read(lst[i].a, w)) del.push(i);
        }
        //cout<<ecnt<<'-';
        if(ecnt-del.size()>=m){
            ecnt-=del.size();
            while(!del.empty()) lst[del.front()].e=0, del.pop();
            ans|=1;
        }
        //cout<<ecnt<<endl;
        /*for(int i=1; i<=n; i++){
            if(!lst[i].e) continue;
            cout<<lst[i].a<<" ";
        }cout<<endl;*/
    }
    cout<<ans;
    return 0;
}
