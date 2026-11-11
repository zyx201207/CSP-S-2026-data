#include<bits/stdc++.h>
using namespace std;
long long b[500005];
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
long long n,m,ans=0;
cin>>n>>m;
for(long long i=1;i<=n;i++){
    cin>>b[i];
}
sort(b+1,b+n+1);
for(long long i=1;i<=n;i++){
    a[n-i+1]=b[i];
}
long long x=1,num=0,cnt=1,f=1;
for(long long i=1;i<=n;i++){
    for(long long j=x;j<=n;j++){
            if(j!=x){
            num+=a[i]-a[j];
            cnt++;
            }
    if(num>m){
            cnt--;
        ans=max(ans,cnt);
        break;
    }
    }
    ans=max(ans,cnt);
   // cout<<cnt<<" "<<num<<endl;
    num-=cnt*(a[i]-a[i+1]);
    x=cnt+i;
    if(x>=n){
        cout<<ans;
        f=0;
        break;
    }
   //cout<<x<<" "<<num<<" "<<cnt<<" "<<ans<<endl;
    }
    if(f){
cout<<ans;
    }
return 0;
}
