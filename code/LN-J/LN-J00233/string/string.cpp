#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p;
ll n;
char k;
ll cnt;
string s;
string ss;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&p);
    while(p--){
        scanf("%lld",&n);
        cin>>k;
        while(n--) s+=k;
    }
    for(ll i=s.size()-1;i>=0;i--){
        ss+=s[i];
    }
    for(ll i=0;i<s.size();i++){
        if(s[i]!=ss[i]) cnt++;
    }
    printf("%lld",cnt/2);
    return 0;
}
