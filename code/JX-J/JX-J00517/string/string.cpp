#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n,l,cnt;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        ll a;
        char c;
        cin>>a>>c;
        l+=a;
        for(int i=1;i<=a;i++) s+=c;
    }
    for(int i=0;i<(l+1)/2;i++) if(s[i]!=s[l-i-1]) cnt++;
    cout<<cnt;
    return 0;
}
