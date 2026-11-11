#include<bits/stdc++.h>
using namespace std;
long long n,k,maxn=-1,v;
long long a[200005];
bool o[200005];
long long b[200005];
void dfs(int z){
    if(z==k+1){
        long long cnt;
        cnt=b[1];
        for(int i=2;i<=k;i++){
            cnt&=b[i];
        }
        if(cnt>maxn){
            maxn=cnt;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(o[i]==0){
            b[z]=a[i];
            o[i]=1;
            dfs(z+1);
            o[i]=0;
        }
    }
    return ;
}
int main(){
    freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
   cin>>n>>k;
   for(int i=1;i<=n;i++){
      cin>>a[i];
   }
   if(k==n){
        long long u=a[1];
     for(int i=2;i<=n;i++)
     {
         u&=a[i];
     }
        maxn=u;
   }
   else if(k==2){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                v=a[i] & a[j];
            }
          //  cout<<i<<" "<<j <<endl;
            maxn=max(maxn,v);
        }

    }
   }
   else if(k==1){
     for(int i=1;i<=n;i++){
        maxn=max(maxn,a[i]);
     }

   }
   else if(k>2){
     dfs(1);
   }
   cout<<maxn;
    return 0;
}
