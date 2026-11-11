#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],x=2147483648,ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,greater<long long>());
    while(x){
        long long sum=0;
        for(int i=1;i<=n;i++){
            if(a[i]&x)sum++;
        }
        if(sum>=m){
            ans+=x;
            for(int i=1;i<=n;i++){
                if(!(a[i]&x)) a[i]=0;
            }
        }
        x/=2;
    }
    cout<<ans;
    return 0;
}
