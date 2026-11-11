#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005];
long long n,m,ans=0;
bool check(int i,int j){
    if(a[i]*(i-j+1)-(s[i]-s[j-1])<=m) return true;
    else return false;
}
int main(){
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    s[0]=0;
    for(int i=1;i<=n;i++){
        s[i]=a[i]+s[i-1];
    }
    for(long long i=1;i<=n;i++){
        if(i*a[i]-s[i]<=m) ans=max(ans,i);
        else{
            int l=1,r=i,mid;
            while(l<=r){
                mid=(l+r)/2;
                if(check(i,mid)==true) r=mid-1;
                else l=mid+1;
            }
            ans=max(ans,i-l+1);
        }
    }
    cout<<ans;
    return 0;
}
