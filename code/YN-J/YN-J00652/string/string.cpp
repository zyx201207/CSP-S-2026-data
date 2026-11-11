#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+5;
int n;
ll s1[N],s2[N];

struct node{
    ll cnt;
    char c;
}a[N];

string s;

int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0);
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].cnt>>a[i].c;
        sum+=a[i].cnt;
        s1[i]=s1[i-1]+a[i].cnt;
    }
    ll ans=0;
    for(ll i=1;i<=sum/2;i++){
        int id=lower_bound(s1+1,s1+1+n,i)-s1,rid=lower_bound(s1+1,s1+1+n,sum-i+1)-s1;
        if(a[id].c!=a[rid].c){
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
