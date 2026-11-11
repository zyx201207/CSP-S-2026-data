#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200000+100],tmax=LLONG_MIN,sum;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=2000&&m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i]&a[j]>tmax){
                    tmax=a[i]&a[j];
                }
            }
        }
    cout<<tmax;
    }else if(n<=2000&&m==n){
        sum=a[1];
        for(int i=2;i<=n;i++){
            sum&=a[i];
        }
        cout<<sum;
    }else if(n<=2000&&m==1){
        for(int i=1;i<=n;i++){
            if(a[i]>tmax){
                tmax=a[i];
            }
        }
        cout<<tmax;
    }
    return 0;
}
