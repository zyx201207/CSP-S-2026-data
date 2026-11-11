#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,sum,ans;
char a;
bool cmp(ll n){
    if(n%2==0){
        return true;
    }return false;
}

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s="";
    cin>>n;
    while(n--){
        cin>>m>>a;
        for(int i=1;i<=m;i++){
            s+=a;
        }
        sum+=m;
    }

    if(cmp(sum)){
        ll l=0,r=sum-1;
        for(ll i=1;i<=sum/2;i++){
            if(s[l]!=s[r]){
                ans++;
                l+=1;
                r-=1;
            }else{
                l+=1;
                r-=1;
            }
        }
    }else{
        ll l=0,r=sum-1;
        for(ll i=1;i<=(sum-1)/2;i++){
            if(s[l]!=s[r]){
                ans++;
                l+=1;
                r-=1;
            }else{
                l+=1;
                r-=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
