#include<bits/stdc++.h>
using namespace std;
const int N=20005;
long long n,a[N],s,ans;
char c[N];
int f(int k){
    long long s=0;
    for(int i=1;i<=n;i++){
        if(s<k&&s+a[i]>k)return c[i];
        s+=a[i];
    }
}
int main(){
      freopen("string.in","r",stdin);
      freopen("string.out","w",stdout);
      cin>>n;
      for(int i=0;i<n;i++){
          cin>>a[i]>>c[i];
          s+=a[i];
      }
      for(int i=1;i<=s/2;i++)
          if(f(i)!=f(i-1))ans++;
      cout<<ans<<endl;
      return 0;
}
