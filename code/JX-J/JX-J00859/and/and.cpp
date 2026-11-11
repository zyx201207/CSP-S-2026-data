#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],ans,b[1000000],c[1000000],cnt,d[1000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
        return 0;
    }
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    int ans1=0;
    //if(m==n-1){
     //   for(int i=1;i<=n;i++){
     //       for(int j=1;j<=n;j++){
      //          for(int k=1;k<=n;k++){
     //               if(i!=k && k!=j && j!=i){
      //                  ans1=ans1&a[i];
      //              }
      //          }
      //          ans=max(ans,ans1);
       //     }
       // }
    //}
    int cnt1;
    for(int i=1;i<=n;i++){
        int cnt=1;
        while(a[i]){
            b[cnt]=a[i]%2;
            cnt++;
            a[i]/=2;
        }
        for(int i=cnt;i>=1;i++){
            c[cnt1]=c[cnt1]*10+b[i];
        }
        cnt1++;
    }
    sort(c+1,c+cnt1);
    for(int i=1;i<=cnt-1;i++){
        while(c[i]){
            int h=c[i]%10,l=0;
            for(int j=1;j<=l;j++){
                h*=2;
            }
            d[i]+=h;
        }
    }
    for(int i=cnt-1;i>n-m;i++){
        ans=ans&d[i];
    }

    cout<<ans;
    return 0;
}

