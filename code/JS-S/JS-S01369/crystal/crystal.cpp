#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,ans;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        int x=m;
        ans=0;
        for(int j=i;j>=1;j--){
            if(x-(a[i]-a[j])>=0) {
                x-=(a[i]-a[j]);
                ans++;
            }
            else break;
        }
        sum=max(sum,ans);
    }
    cout<<sum;
    return 0;
}
