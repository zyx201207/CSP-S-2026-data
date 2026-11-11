#include<bits/stdc++.h>
using namespace std;
long long yuan[500004]={};
int main(){
priority_queue<int,vector<int>,greater<int> > q;
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
long long n,m,a,ans=1;
bool bj=0;
cin>>n>>m;
for(long long i=1;i<=n;i++){
  cin>>a;
  if(a!=i){
    bj=1;
  }
  q.push(a);
}
if(bj==1){
    long long xb=1,bj1;
bool bj2=0;
while(1){
   if(q.empty()==1){
    break;
   }
   yuan[xb]=q.top();
   xb++;
   q.pop();
   if(xb>=2){
     bj1=yuan[2]-yuan[1];
     if(yuan[xb]-yuan[xb-1]!=bj1){
        bj2=1;
     }
   }
}
if(bj2==0){
   m=m/bj1;
    for(long long i=1;i<=n;i++){
        if((i+1)*i/2>m){
            ans=i-1;
       }
    }
    cout<<ans;
   return 0;
}
long long mb=yuan[1],s=0,dq=2,zs=1;
int s1=0;
for(long long i=1;i<=xb-2;i++){
    while(1){
       if(mb+(m-s)/zs<yuan[dq] and dq<=n){
           if((m-s)/zs>0){
            mb=mb+(m-s)/zs;
          s=s+(m-s)/zs*zs;
           }
       }
       else if(dq<=n){
         s=s+(yuan[dq]-mb)*zs;
         zs++;
          mb=yuan[dq];
          dq++;
          while(1){
            if(yuan[dq]==yuan[dq-1]){
               dq++;
                zs++;
            }
            else{
               break;
            }
          }
       }
       else{
        ans=max(ans,zs);
         break;
       }
        mb++;
        s=s+zs;
       if(s>m){
         mb--;
         s=s-zs;
         ans=max(ans,zs);
         break;
       }
    }
    s=s-(mb-yuan[i]);
    zs--;
    s1++;
}
}
else{
    for(long long i=1;i<=n;i++){
        if((i+1)*i/2>m){
            ans=i;
            cout<<ans;
        return 0;
        }
    }
}
cout<<ans;
return 0;
}
