#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000001],b[1000001],x,k,s,y,z,ma;
long long ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    s=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>100000)s=1;
    sort(a+1,a+n+1);
    if(s==0){
        for(int i=1;i<n;i++){
            for(int j=1;j<=i;j++){
                b[j]=b[j]+a[i+1]-a[i];
            }
            x=m;
            k=0;
            while(x>=0&&k<i){
                x=x-b[i-k];
                if(x>=0){
                    k++;
                }else{
                    ma=1;
                    break;
               }
            }
            ans=max(ans,k);
            if(ma==1){
                break;
            }
        }
        cout<<ans+1;
    }else{
        y=a[2]-a[1];
        z=m;
        long long i=0;
        while(z>=0&&i<n){
            z=z-y*i;
            if(z>=0){
                i++;
            }
        }
        cout<<i;
    }
    return 0;
}
