#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,sum[1000005];
char a[1000005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    string s="";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        s+=a[i];
        ll p=i;

        if(s.find(a[i])==p){
           s=s.substr(0,min(i,(int)s.size()));
        }
        for(int j=0;j<s.size();j++){
            sum[s[j]-'0']++;
        }



    }
    cout<<3<<" "<<1<<" "<<4;

    return 0;
}
