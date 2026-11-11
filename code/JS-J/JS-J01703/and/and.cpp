#include<bits/stdc++.h>
#define int long long
using namespace std;
long long a[200010];
long long b[200010];
long long c[35];
long long d[35];
long long dp[200010];
long long zd=0,m,n;
string to2(int n){
    string m="";
    int pi=0;
    d[0]=1;
    for(int i=1;i<=35;i++){
     c[i]=2*c[i-1];
    }
    for(int i=35;i>=1;i--){
        if(n>c[i]){
            pi=i;
            n=n-c[i];
            m=m+"1";
        }
        else if(pi>0)m=m+"0";
    }
    return m;
}
signed main(){
 freopen("and.in","r",stdin);
 freopen("and.out","w",stdout);

   cin>>n>>m;
   for(int i=1;i<=n;i++){
    cin>>a[i];
   }
   if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                zd=max(zd,a[i]&a[j]);
            }
        }cout<<zd;
        return 0;
   }



  if(m==1){
    sort(a+1,a+1+n);
    cout<<a[n];
    return 0;
  }
  if(m==n){
     int  x=a[1];
    for(int i=2;i<=n;i++){
        x=x&a[i];
    }
    cout<<x;
    return 0;
  }
  c[0]=1;
  c[1]=2;
  for(int i=2;i<=35;i++){
    c[i]=2*c[i-1];
  }int k=0;
  sort(a+1,a+1+n);
  for(int i=1;i<=n;i++){
       string d=to2(a[i]);
       string f=to2(a[i-1]);
       for(int j=1;j<=35;j++){
        if(a[i]==c[j]-1)k++;
       }
       if(k==n){
            int q=a[n];
        for(int s=n-1;s>n-m;s--){
            q=q&a[s];
        }
       cout<<q;
       return 0;
       }
       else {
            int q=a[n];
          if((long long)d.size()==(long long)f.size()){
            for(int s=n-1;s>n-m;s--){
               q=q&a[s];
             }
            cout<<q;
            return 0;
          }
       }


   }
   return 0;
}
