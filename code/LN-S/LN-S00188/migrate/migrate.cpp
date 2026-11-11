#include<bits/stdc++.h>
using namespace std;
int c,t,ans,a[2000005],b[2000005];
int an(int n,int d,int s){
    for(int i=n+1;i<=n+d;i++){
        if(a[i]<=a[n]+d)
            b[i]++;
        if(i>s){
            return 0;
        }
        an(i,d,s);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int k=1;k<=t;k++){
        ans=0;
        int n,d;
        a[2000005]={0};
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }for(int j=1;j<=n-3;j++){
            b[2000005]={0};
            an(j,d,n);
            for(int i=1;i<=n;i++){
                if(b[i]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
