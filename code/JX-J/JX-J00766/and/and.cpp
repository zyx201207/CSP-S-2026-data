#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100005;
struct num{
    ll value;
    int cnt;
}a[maxn];
int count(int n){
    int cnt=0;
    while(n){
        if(n&1){
            cnt++;
        }
        n>>=1;
    }
    return cnt;
}
bool cmp(const num &x,const num &y){
    return x.cnt >= y.cnt;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].value;
    }
    for(int i=1;i<=n;i++){
        a[i].cnt=count(a[i].value);
    }
    sort(a,a+n+1,cmp);
    ll ans=a[1].value;
    for(int i=2;i<=m;i++){
        ans &= a[i].value;
    }
    cout<<ans<<endl;
    return 0;
}
