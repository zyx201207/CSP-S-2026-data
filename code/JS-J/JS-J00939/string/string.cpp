//i think it can be an ACcode
//100pts need check
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
int n;

struct node{
    ll a;
    char c;
}s[N];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
    }
    ll ans=0;
    int i=1,j=n;
    while(1){
        if(i>=j) break;
        if(s[i].c==s[j].c){
            ll x=min(s[i].a,s[j].a);
            s[i].a-=x;
            s[j].a-=x;
        }else{
            ll x=min(s[i].a,s[j].a);
            s[i].a-=x;
            s[j].a-=x;
            ans+=x;
        }
        if(s[i].a==0){
            i++;
        }
        if(s[j].a==0){
            j--;
        }
    }
    cout<<ans;
    return 0;
}
//Trick||Treat!
