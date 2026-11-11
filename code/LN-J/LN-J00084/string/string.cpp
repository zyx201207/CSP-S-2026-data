#include<bits/stdc++.h>//qiu2le.,ce4shi4yang4li4gao3xiao3yi4dian3...
using namespace std;
typedef long long ll;
string s;
ll n;
void f1(){
    ll cnt=0;
    ll mid=s.size()/2;
    for(ll i=mid-1,j=mid+1;j<s.size();i--,j++){
        if(s[i]!=s[j])cnt++;
    }
    cout<<cnt;
    return;
}
void f2(){
    ll cnt=0;
    ll mid=s.size()/2;
    for(ll i=mid-1,j=mid;j<s.size();i--,j++){
        if(s[i]!=s[j])cnt++;
    }
    cout<<cnt;
    return;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    bool f=1;
    char last;
    for(ll i=1;i<=n;i++){
        long long a;char c;
        cin>>a>>c;
        while(a--)s+=c;
        if(i==1)last=c;
        else if(last!=c)f=0;
    }
    if(f){
        cout<<0;
        return 0;
    }
    if(s.size()%2)f1();
    else f2();
    return 0;
}
