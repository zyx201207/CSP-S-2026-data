#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main (){
   freopen ("string.in","r",stdin);
   freopen ("string.out","w",stdout);
    cin.tie();
    ll n,cnt=0,q=0,ans=0;
    cin>>n;
    ll a;
    char s;
    string l;
    for (int i=1 ; i<=n ; i++){
        cin>>a>>s;
        ans+=a;
        for (q ; q<ans ; q++){
          l[q]=char(s);
        }
    }
    string ck;
    for (int j=0; j<ans; j++){
        ck[j]=l[ans-j-1];
    }
    for (int x=0; x<ans ; x++){
        if (ck[x] != l[x] and int(ck[x]) >= 48) {
                cnt++;
        }
    }
    cout<<cnt/2+cnt%2;
    return 0;
}
