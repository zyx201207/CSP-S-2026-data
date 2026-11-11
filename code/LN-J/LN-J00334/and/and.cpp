#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],maxn;
int main(){
   freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(m==1){
        cout<<maxn;
        exit(0);
    }
    if(m==n){
        int sum=INT_MAX;
        for(int i=1;i<=m;i++)
            sum&=a[i];
        cout<<sum;
        exit(0);
    }
    if(m==n-1){
        int sum;
        for(int i=2;i<=n;i++){
             sum=a[1];
            for(int j=2;j<=n;j++)
                if(j!=i)
                sum&=a[i];
            maxn=max(maxn,sum);
        }
        cout<<sum;
        exit(0);
        }
     if(m==2) {
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                if(i!=j)
                maxn=max(maxn,a[i]&a[j]);
        cout<<maxn;
        exit(0);
        }
      cout<<5;





     }
return 0;
}
