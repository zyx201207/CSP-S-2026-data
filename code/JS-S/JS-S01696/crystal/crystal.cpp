#include<bits/stdc++.h>
using namespace std;
const long long N=500005;
long long m,n,a[N],ans=0;

bool cmp(long long a,long long b){
    return a<b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    for(long long i=0;i<n;i++){
        long long s=0,num,j=i-1;
        for(j;j>=0;j--){
            s+=a[i]-a[j];
            if(s>m) break;
        }
        ans=max(ans,i-j);
    }
    cout<<ans;
    return 0;
}
