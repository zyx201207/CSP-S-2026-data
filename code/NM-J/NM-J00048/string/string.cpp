#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
struct InFo{
    ll l,s,e;
    char col;
} a[N];
int n;
int zd;
ll ans;
ll len;
char c[N];
bool cmp(InFo A,InFo B){
    return A.s<B.s;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    a[0].e=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].col;
        a[i].s=a[i-1].e+1;
        a[i].e=a[i].s+a[i].l-1;
        len+=a[i].l;
        for(int j=a[i].s;j<=a[i].e;j++){
            c[j]=a[i].col;
        }
    }
    for(int i=1;i<=len/2;i++){
        ans+=(c[i]==c[len-i+1]?0:1);
    }
    cout<<ans;
    return 0; 
}
