#include<bits/stdc++.h>
using namespace std;
const int N=5e5+8;
long long a[N];
long long cnt=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;cin>>n>>m;
    bool all =1,deng=1;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i)all=0;
    }sort(a+1,a+n+1);
    for(long long i=2;i<=n-1;i++){
        if(a[i]-a[i-1]!=a[i+1]-a[i])deng=0;
    }
    if(all==1){

       for(long long i=n;i>=1;i--){
            if(a[i]!=a[n]){
                while(a[i]!=a[n]){
                    a[i]++;
                    m--;
                    if(m<=0)break;
                }if(m<=0)break;
            }
            if(a[i]==a[n]){
                cnt++;
            }
       }
       cout<<cnt;
       return 0;
    }
    else if(deng==1){
        for(long long i=n;i>=1;i--){
            if(a[i]!=a[n]){
                while(a[i]!=a[n]){
                    a[i]++;
                    m--;
                    if(m<=0)break;
                }if(m<=0)break;
            }
            if(a[i]==a[n]){
                cnt++;
            }
       }
       cout<<cnt;
       return 0;
   }
   else {
        long long Max=-1;
        for(long long i=2;i<=n;i++){
            cnt=1;
            long long k=m;
            for(long long j=i-1;j>=1;j--){
                if(a[j]!=a[i]){
                    long long cha=a[i]-a[j];
                    k-=cha;
                    if(k<0)break;
                    cnt++;
                }if(a[i]==a[j])cnt++;
            }
            Max=max(Max,cnt);

        }cout<<Max;
    }


    return 0;
}
