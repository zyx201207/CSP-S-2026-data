#include<bits/stdc++.h>
#define pcr(i,a,b,c) for(int i=a;i<=b;i+=c)
#define rcp(i,a,b,c) for(int i=a;i>=b;i-=c)
#define pii pair<int,int>
#define pil pair<int,ll>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e6+3;
const int mod=998244353;
const ll inf=1e9;
int n;
ll d,x[N],diff[N];
void solve1(ll dx){
    if(d<dx*2){
        cout<<0<<"\n";
        return;
    }
    ll based=dx,i=0;
    while(based>d) based-=d,i++;
    if(i%2==0){
        cout<<"0\n";
        return;
    }else{
        cout<<n-(i*2+1)+1<<"\n";
        return;
    }
}
void solve(){
    cin>>n>>d;
    bool flag=true;
    pcr(i,1,n,1){
        cin>>x[i];
        diff[i]=x[i]-x[i-1];
        if(i>2&&diff[i]-diff[i-1]!=0) flag=false;
    }
    if(flag){solve1(diff[n]);return;}
    cout<<0<<"\n";
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c;
    cin>>c;
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
