#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
bool cmp(long long x,long long y){
    return x<y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    if(n<1e5){
        long long ans=0,cnt=0;
        long long m2;
        for(long long i=1;i<=n;i++){
            cnt=0;
            m2=m;
            for(long long j=1;j<=n;j++){
                b[j]=a[i]-a[j];
            }
            sort(b+1,b+n+1,cmp);
            for(long long j=1;j<=n;j++){
                if(b[j]>=0){
                    m2-=b[j];
                    if(m2<0) break;
                    cnt++;
                }
            }
            ans=max(ans,cnt);
        }
        cout<<ans;
    }
    else{
        cout<<min(2*m/(a[2]-a[1])/(a[2]-a[1]),n);
    }
    return 0;
}
