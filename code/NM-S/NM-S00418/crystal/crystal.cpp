#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,x=0,b=0;
    cin>>n>>m;
    long long a[n];for(long long i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    while(m!=0){
    if(a[b+1]-a[b]<=m){x+=1;m=m-(a[b-1]-a[b]);a[b+1]=a[b];}
    if(b==n){cout<<x;return 0;}
    b+=1;
    }
    cout<<x;
    return 0;
}
