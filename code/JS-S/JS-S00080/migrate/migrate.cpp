#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long t,n,d,x[N],a[N],b[N];
bool vis[N];
long long cal(int k) {
    long long lenl1=0,lenl2=0,lenr1=0,lenr2=0;
    for(int i=k+2;i<=n;i++){
        if(a[i]==2){
            if(lenr1!=0)break;
            if(lenr1==0)lenr2++;
            if(i==n-2)break;
        }else if(a[i]==1)lenr1++;
        else break;
        vis[i]=1;
    }
    for(int i=k-1;i>=1;i--){
        if(a[i]==2){
            if(lenl1!=0)break;
            if(lenl1==0)lenl2++;
        }else if(a[i]==1)lenl1++;
        else break;
        vis[i]=1;
    }
    if((lenr2+lenr1)%2==1){
        return (lenr1+lenl1+2)*(lenr2+lenl2+1);
    }else{
        return (lenr1+1)*(lenl1+1)+(lenr1+lenl1+2)*(lenr2+lenl2);
    }
}
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>t>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<=n;i++){
            a[i]=-1;
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]>d){
                        cout<<i<<" "<<j<<" "<<x[j]<<endl;
                    a[i]=j-i-1;
                    break;
                }
            }
            if(a[i]==-1)a[i]=n-i;
        }
        for(int i=1;i<=n;i++)cout<<a[i]<<" ";
        cout<<endl;
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]==2&&a[i+1]==2&&vis[i]==0)ans+=cal(i);
        }
        for(int i=1;i<=n;i++)vis[i]=0;
        cout<<ans<<endl;
    }
    return 0;
}
