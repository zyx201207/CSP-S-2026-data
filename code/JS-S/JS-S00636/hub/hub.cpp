#include<bits/stdc++.h>
using namespace std;
#define N 500007
#define int long long
int n,m,t=0;
int a[N],sol[N];
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sol[i]=sol[i-1]+a[i];
     //   cout<<sol[i]<<" ";
    }
    for(int i=1;i<=n;i++){
        int l=i;
        int ans=0;
        while(l>=1) {
            if(sol[i]-sol[l]+ans<=m){
                ans+=sol[i]-sol[l];
                l++;
            }else break;
        }
      //  cout<<i-(l+1)+1<<endl;
        t=max(t,i-l+1);
    }
    cout<<t<<endl;
    return 0;
}
