#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],sum[N],ans;
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
    }
    long long z=a[1];
    for(long long i=n;i>=1;i--){
        //if(sum[i]>=m) ans=i;
        if(m<=sum[i]-a[i]+z) ans=i-1;
        else{
            break;
        }
    }
    cout<<ans;
    return 0;
}
