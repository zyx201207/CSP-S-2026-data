#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,ans=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==0){
        cout<<1;
    }
    else{
        sort(a+1,a+1+n);
        for(int i=2;i<=n;i++){
            long long cu=1,k=m;
            for(int j=i-1;j>=1;j--){
                if(k>=a[i]-a[j]){
                    cu+=1;
                    k-=(a[i]-a[j]);
                    ans=max(ans,cu);
                }
                else{
                    continue;
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
