#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long a[maxn],n,m,mm=-1,mz=-1,cnt,sum,zz[maxn],llk;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        llk+=a[i];
    }
    sort(a,a+n);
    if((a[0]+a[n-1])*(n-1)/2==llk){
        for(long long i=0;i<n;i++){
            if((a[0]+a[i-2])*(i-2)/2<=m){
                if((a[0]+a[i-2])*(i-2)/2<=m){
                    mz=max(mz,i);
                }
            }
        }
        cout<<mz;
        return 0;
    }
    for(long long i=0;i<n;i++){
        cnt=0;
        for(int j=i;j>=0;j--){
            if(cnt<=m){
                cnt+=(a[i]-a[j]);
            }
        }
        mm=max(mm,cnt);
        if(mm==cnt){
            mz=max(i,mz);
        }
    }
    cout<<mz;
    return 0;
}
