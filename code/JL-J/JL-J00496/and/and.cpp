#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){return a>b;}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,sum=0;
    cin>>n>>m;
    long long a[n+1]={0};
    for(long long i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    sum=a[1];
    for(long long i=2;i<=m;i++){
        sum&=a[i];
    }
    cout<<sum;
    return 0;
}
