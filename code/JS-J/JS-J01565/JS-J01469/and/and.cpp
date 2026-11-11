#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
  ll n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>a[i];
  sort(a+1,a+n+1);
  ll cnt=a[n];
  for(int i=n;i>=n-m+1;i--){
    cnt=cnt^a[i];
  }
  cout<<cnt;
    return 0;
}
