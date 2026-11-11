#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
 struct node{
          long long num;
          int pos;
        }b[200005];
int judge(long long x){
    long long tent=0;
    while(x>0){
        if(x%2==1) tent++;
        x=x/2;
    }
    return tent;
}
bool cmp(node x,node y){
    return x.num<y.num;
}
int main(){
   freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
     cin>>n>>m;
     for(int i=1;i<=n;i++){
        cin>>a[i];
     }
      if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n];
      }
      else if(m==2)
      {
        long long maxx=0;
        for(int i=1;i<=n;i++){
          for(int j=1;j<=i;j++){
             if((a[i]&a[j)>maxx) maxx=(a[i]&a[j]);
          }
        }
        cout<<maxx;
      }
      else if(m==n){
        long long ans=a[1];
        for(int i=2;i<=n;i++){
          ans=(a[i]&ans);
          cout<<ans;
        }
      }
      else if(m==n-1){
         for(int i=1;i<=n;i++){
           b[i].num=judge(a[i]);
           b[i].pos=i;
           sort(b+1,b+n+1,cmp);
         }
         a[b[0].pos]=1024*1024;
         long long ans=a[1];
        for(int i=2;i<=n;i++){
          ans=(a[i]&ans);
          cout<<ans;
        }
      }
    return 0;
}
