#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,p,s=0;
    cin>>n>>m;
    int a[n+1]={0};
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n%2)p=a[(n+1)/2];
    else p=a[n/2];
    for(long long i=1;i<=n;i++){
        if(a[i]<=p)s++;
    }
    cout<<s;
    return 0;
}
