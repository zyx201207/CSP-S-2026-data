#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long bitss(long long x){
    long long cnt=0;
    while(x){
        if(x%2==1) cnt++;
        x/=2;
    }
    return cnt;
}
bool cmp(long long a,long long b){
    if(bitss(a)==bitss(b)) return a>b;
    return bitss(a)>bitss(b);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
//    for(long long i=1;i<=n;i++) cout<<a[i]<<" ";
    long long sum=a[1];
    for(long long i=2;i<=m;i++) sum&=a[i];
    cout<<sum;
    return 0;
}
