#include<bits/stdc++.h>
using namespace std;
int const maxn=5*1e5+10;
int n;
long long m;
long long a[maxn];
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        long long summ=m;
        for(int j=i+1;j<=n;j++){
            if(a[i]-a[j]>summ){
                ans=max(ans,j-i);
                break;
            }
            summ=summ-(a[i]-a[j]);
            if(summ>=0 && j==n){
                ans=max(ans,n-i+1);
            }
        }
    }
    cout<<ans;
    return 0;
}
