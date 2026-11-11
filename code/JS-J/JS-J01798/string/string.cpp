#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll a[N];
int main(){
    freopen("string,in","r",stdin);
    freopen("string,out","w",stdout);
    ll n;
    cin>>n;
    char c;
    string s="";
    for(ll i=1;i<=n;i++){
        cin>>a[i]>>c;
        for(ll j=1;j<=a[i];j++){
            s+=c;
        }
    }
    string t=s,t1=s;
    reverse(s.begin(),s.end());
    string s1=s;
    if(s1==t){
        cout<<0;
        return 0;
    }
    ll len=s.size()-1;
    ll sum=0;
    for(ll i=0;i<len-1;i++){
        if(t1==s1){
            break;
        }
        t1[i]=t1[len-1];
        sum++;
    }
    ll num=0;
    for(ll i=len-1;i>=1;i--){
        if(t==s1){
            break;
        }
        t[i]=t[0];
        num++;
    }
    ll mx=max(sum,num);
    cout<<mx;
    return 0;
}
