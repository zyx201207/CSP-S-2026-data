/*
uid=305928 last fight

azayagana risouhatasutsurukiyo
konoyonoyume subetenosete
ima ima saa kirisaite
tashikana kotowariminna urayamu
mitasarenu sekainoitadakide!

For lovely Tenshi Hinanawi
 */


/*
Why CSP-S has no WC flags.

And the toliet's quality... familiar.

Three times lose here.

It cannot be four times.
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],s[1000005];
signed main(){
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for (int i=1;i<=n;i++){
    cin>>a[i];
  }
  sort(a+1,a+1+n);
  s[0]=0;
  s[1]=a[1];
  for (int i=2;i<=n;i++){
    s[i]=s[i-1]+a[i];
  }
  int l=1,ans=1;
  for (int r=2;r<=n;r++){
    while (1){
      int p=(r-l+1)*a[r]-(s[r]-s[l-1]);
      if (p>m)l++;
      else break;
    }
    ans=max(ans,r-l+1);
  }
  cout<<ans<<"\n";
  return 0;
}
