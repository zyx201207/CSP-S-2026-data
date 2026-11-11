#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n=0,m=0,ans=1;
    scanf("%lld %lld",&n,&m);
    vector<long long> a(n+2);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a.begin()+1,a.begin()+n+1);
    
    long long l=1,r=1,value=0;
    while(l<=r and r<=n){
        if(value>m){
            value-=a[r]-a[l];
            l++;
        }
        if(value<=m){
            ans=max(ans,r-l+1);
            value+=(r-l+1)*(a[r+1]-a[r]);
            r++;
        }
    }

    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}