#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,i,a[300005],num,x[300005],qz[5005][3005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
  ////  cout<<1<<'\n';
    num=0;
   for(i=1;i<=n;i++){
        cin>>a[i];
        num=max(num,a[i]);
       // cout<<i<<' '<<n<<'\n';
    }
    for(i=n;i>=1;i--){
        for(ll j=1;j<=num;j++){
            qz[i][j]=qz[i+1][j];
        }
        qz[i][a[i]]++;
    }
    memset(x,0,sizeof(x));
    for(i=1;i<=n;i++){
       //     cout<<1<<'\n';
      //  cout<<1<<'\n';
        ll f=0,ji=0;
        for(int j=i;j<=n;j++){
                if(f==1&&a[j]==ji){
                    f=0;
                }
                if(f==1){
                    qz[i][a[j]]--;
                    continue;
                }
                if(qz[i][a[j]]>1){
                    f=1;
                    ji=a[j];
                    qz[i][a[j]]--;
                    continue;
                }
                x[a[j]]++;
          //  cout<<i<<' '<<j<<'\n';
        }
    }
    for(i=1;i<=m;i++){
        cout<<x[i]<<' ';
    }
    return 0;
}
