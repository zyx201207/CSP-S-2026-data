#include<bits/stdc++.h>
using namespace std;
const long long N=1e18;
const int M=1e6;
long long a[M];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long n,m,sum=0,mx=0,mx_1=0,mi=N;
    cin>>n>>m;
    long long m1=m;
    for(int i=0;i<n;i++){
         cin>>a[i];
         mx_1=max(mx,a[i]);
         mi=min(mi,a[i]);
    }
    for(long long i=mi;i<=mx_1;i++){
        for(int j=0;j<n;j++){
            if(i>=a[j]&&m-i+a[j]>=0){
                m=m-(i-a[j]);
                sum++;
            }
        }
        mx=max(mx,sum);
        sum=0;
        m=m1;
    }
    cout<<mx;
    return 0;
}
