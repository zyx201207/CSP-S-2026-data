#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];char b[200005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  ll n,cnt=0,ans=0;
  cin>>n;
  string s="";
  for(ll i=1;i<=n;i++){
    cin>>a[i]>>b[i];
    cnt+=a[i];
    for(ll j=1;j<=a[i];j++){
        s=s+b[i];
    }
  }
  cnt/=2;
  for(ll i=0;i<cnt;i++){
      if(s[i]!=s[cnt*2-i-1])ans++;
  }
  cout<<ans;
    return 0;
}
