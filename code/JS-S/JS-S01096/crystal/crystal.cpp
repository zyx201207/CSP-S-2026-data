#include<bits/stdc++.h>
#define N 500001
using namespace std;
long long a[N];
int n;
long long m;
bool check(int l,int r,long long ot){
    if(ot*(r-l)-a[r-1]+a[l-1]>m)return false;
    return true;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
    }
    int l,r,mid;
    int ans=0;
    for(int i=1;i<=n;i++){
        l=1,r=i;
        while(l<r){
            mid=(l+r)>>1;
         //   cout<<mid<<" "<<i<<" "<<(-(a[r-1]-a[l-1]-(a[i]-a[i-1])*(r-l)))<<" ";
            if(check(mid,i,a[i]-a[i-1])){
             //   cout<<"ck"<<endl;
                r=mid;
            }
            else {
             //   cout<<"uc"<<endl;this code is correct
                l=mid+1;
            }
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
