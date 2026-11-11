#include<bits/stdc++.h>
#define iwill using
#define ak namespace
#define csps std;
iwill ak csps
long long n,m,a[600005],s[600005];
bool check(int mid,int x){
    if((x-mid+1)*a[x]-s[x]+s[mid-1]<=m){
        return false;
    }
    return true;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    long long cz=0,ans=1,cc=0;
    long long finans=-1;
    for(long long i=1;i<=n;i++){
        long long l=1,r=i;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,i)){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        ans=i-l+1;
        finans=max(finans,ans);
    }
    cout<<finans<<endl;
    return 0;
}
