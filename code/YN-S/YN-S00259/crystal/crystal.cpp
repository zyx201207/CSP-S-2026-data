#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
LL n,m,pin=0,sum=0;
cin>>n>>m;
vector<LL> gh(n,0);
for(LL i=0;i<n;i++){
   cin>>gh[i];
   pin+=gh[i];
}
pin=pin/n;
 sort(gh.begin(),gh.end());
 vector<LL> kl(n,0);
 for(LL i=0;i<n;i++){
   kl[i]=pin-gh[i];
}
sort(kl.begin(),kl.end());
  for(LL i=n;i>=0;i--){
     if(kl[i]>=0&&m>=kl[i]){
      sum+=1;
      m=m-kl[i];
     }

}
cout<<sum;
return 0;
}
