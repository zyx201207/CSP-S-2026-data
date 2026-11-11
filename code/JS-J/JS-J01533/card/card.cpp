#include<bits/stdc++.h>
using namespace std;
#define int long long
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
int T=1,n,m,a[500010],t[300010],tt[300010];
bool check=true;
void solve(){
    cin>>n>>m;
    rep(i,1,n){
        cin>>a[i];
        if(a[i]<a[i-1]){
            check=false;
        }
        tt[a[i]]++;
    }
    if(n<=500){
        rep(i,1,n){
            vector<int>card;
            card.clear();
            rep(j,i,n){
                if(!card.empty()){
                    rep(k,0,card.size()-1){
                        if(card[k]==a[j]){
                                int qwq=card.size()-1;
                            while(qwq>=k){
                                card.pop_back();
                                qwq--;
                            }
                            break;
                        }
                    }
                }
                card.pb(a[j]);
            }
            rep(i,0,card.size()-1){
                t[card[i]]++;
            }
        }
        rep(i,1,m){
            cout<<t[i]<<" ";
        }
        return;
    }
    if(check){
        rep(i,1,m){
            cout<<tt[i]<<" ";
        }
        return;
    }
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    //cin>>T;
    while(T--){
        solve();
    }
}
