#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long s[500005];
long long ans=1;
//map<long long,int> ma;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //ma[a[i]]++;
    }
   // cout<<ma.size()<<'\n';
    sort(a+1,a+n+1);
    if(n<=20000){
        long long v=m;
        ans=1;
        for(long long i=1;i<=n;i++){
               v=m;
               long long k=1;
            long long j=i-1;
            bool fl=0;
            for(j=i-1;j>=1;j--){
                if(v>=a[i]-a[j]){
                    v-=a[i]-a[j];
                    k++;
                }else{
                    fl=1;
                    ans=max(ans,k);
                    break;
                }
            }
            if(!fl)ans=max(ans,i);
        }
    }else{
        long long r=0;
        for(long long l=1;l<=n;l++){
            if(r<l)r=l;
            while(r+1<=n&&m>=abs(a[r+1]-a[r])*(r-l+1)){
                m-=abs(a[r+1]-a[r])*(r-l+1);
                r++;
                ans=max(ans,r-l+1);
                //cout<<m<<'\n';
            }
            ans=max(ans,r-l+1);
            if(r==n)break;
            m+=a[r]-a[l];
        }
    }
    cout<<ans;
    return 0;
}
