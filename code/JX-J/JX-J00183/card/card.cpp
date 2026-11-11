#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll n,m;
ll a[N]={0};
ll b[N]={0};
ll x=n;
bool f=0;
ll t[N]={0};
deque<ll> qq;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]<=m){
            f=1;
        }
    }
    if(f==0){
        cout<<0<<" "<<0<<" "<<0;
        return 0;
    }else{
        cout<<n<<" "<<m<<" "<<m;
        return 0;
    }
    return 0;
}
