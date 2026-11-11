#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[200010];
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a,a+n+1);
    long long maxx=-1;
    for(int i=1;i<=n-m+1;i++){
        long long ans=a[i];
        for(int j=1;j<m;j++){
            ans&=a[j+i];
        }
        maxx=max(ans,maxx);
    }
    cout<<maxx;
    return 0;
}
