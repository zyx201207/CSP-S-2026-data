#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
struct wei{
    ll shu;
    char c;
}a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll len=0;
    ll n;
    ll ans=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        cin>>a[i].shu>>a[i].c;
    }
    bool flag=0;
    for(int i=1;i<n;i++){
        if(a[i].c!=a[i+1].c){
            flag=1;
        }
    }
    if(flag==0){
        cout<<0;
        return 0;
    }
    if(n==2){
        cout<<min(a[1].shu,a[2].shu);
        return 0;
    }
    if(n%2==0){
        len=n/2;
    }
    else{
        len=n/2+1;
    }
    for(int i=1;i<=len;i++){
        if(a[i].c==a[n-i+1].c && a[i].shu==a[n-i+1].shu){
            continue;
        }
        else{
            if(a[i].c==a[n-i+1].c){
                ans+=max(a[i].shu,a[n-i+1].shu)-min(a[i].shu,a[n-i+1].shu);
                continue;
            }
            else if(a[i].shu==a[n-i+1].shu){
                ans+=a[i].shu;
            }
            else{
                ans+=max(a[i].shu,a[n-i+1].shu);
            }
        }
    }
    cout<<ans;
    return 0;
}
