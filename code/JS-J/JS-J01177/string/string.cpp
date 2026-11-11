#include<bits/stdc++.h>
using namespace std;
int gcd(int n,int m){
    int e,r;
    e=m,r=n;
    while(r!=0){
        int x=r;
        r=e%r;
        e=x;
    }
    return e;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s1,s2;
    long long ans=0;
    for(int i=1;i<=n;i++){
      int x;
      char y;
      scanf("%d",&x);
      cin>>y;
      string c;
      for(int j=1;j<=x;j++){
           c+=y;
      }
      s1+=c;
      s2=c+s2;
    }
    for(int i=0;i<=s1.size()/2-1;i++){
       if(s1[i]!=s2[i]){
        ans++;
       }
    }
    cout<<ans;
    return 0;
}
