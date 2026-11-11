#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int ans;
int x;
int n;
long long m;
bool check(int q){
    long long tmp=m;
    for(int i=1;i<=n;i++){
        if(a[i]<=a[q]){

            tmp-=a[q]-a[i];
            if(tmp<0){
                return 0;
            }
            x++;
        }
    }
    return 1;
}
bool cmp(int z,int y){
    return z>y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    long long l=1,r=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    while(l<=r){
        int mid=(l+r)/2;
        x=0;
        if(check(mid)){
            r=mid-1;
        }
        else{
            l=mid+1;
        }ans=max(x,ans);
    }
    cout<<ans;
    return 0;
}
