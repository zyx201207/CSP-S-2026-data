#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll n,a[100000000+10];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll t;
        char t1;
        cin>>t>>t1;
        a[ll(t1)]+=t;
        for(ll j=1;j<=t;j++){
            s+=t1;
        }
    }
    ll l1=s.size()-1,cnt=0;
    for(ll i=0,j=l1;i<l1,j>=0;i++,j--){
        if(j<=i){
            break;
        }
        if(s[i]!=s[j]){
            if(a[int(s[i])]>=a[int(s[j])]){
                s[j]=s[i];
            }else{
                s[i]=s[j];
            }
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
