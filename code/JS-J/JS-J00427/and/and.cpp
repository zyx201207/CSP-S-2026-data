#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
long long k;
long long c=0;
long long h(int x){
    c=0;
    while(x!=0){
        c++;
        int w=x%2;
        x/=2;
        k=k*10+w;
    }
    return k;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    long long x=h(a[n]);
    long long y=h(a[n-1]);
    long long ans=0;
    while(x!=0&&y!=0){
        int r=x%10;
        int t=y%10;
        if(r==t)ans++;
        x/=10;
        y/=10;
    }
    cout<<ans;
    return 0;
}
