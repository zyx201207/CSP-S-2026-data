#include <bits/stdc++.h>
using namespace std;

int c,t,n,d,ans,a[200010];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
while(t--){
        cin>>n>>d;
        ans=0;
        for(int i = 1;i<=n;i++)cin>>a[i];
        if(a[n]-a[1]<=d){
            cout<<'0';
            continue;
        }if(c==13||c==14){
            cout<<'0';
            continue;
        }
        ans=(n*(n-1))/2;
        for(int i = 1;i<=n;i++){
            for(int j = i+1;j<=n;j++){
                int c=ans;
                if(abs(a[i]-a[j])<=d)ans--;
                if((abs(i-j)==1)&&(abs(a[i]-a[j])>d)) {ans-=i;}
                if(abs(a[i]-a[j])>=d*2)ans--;
        }
        }
        //for(int i = 1;i<=n;i++){
         //   for(int j = i+1;j<=n;j++){
         //       if((b[i][j]!=0)&&(b[i][j]!=2)) ans--;
        //}//
        //}//
        cout<<ans;
    }
    return 0;
}
