#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
bool check(int goal){
    unsigned long long sum=0;
    for(int i=1;i<goal;i++){
        if(sum+(a[goal]-a[i])>m){
            return false;
        }
         sum+=a[goal]-a[i];
    }
    return sum<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int l=1,r=n,ans=1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}


