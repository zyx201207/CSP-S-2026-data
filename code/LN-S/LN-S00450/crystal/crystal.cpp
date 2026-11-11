#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
long long n,m,c=0,d=0;
cin>>n>>m;
for(long long i=1;i<=n;i++){
    cin>>a[i];
}sort(a+1,a+n+1);
long long b=a[2]-a[1];
c=m/b;
for(long long i=1;i<=n;i++){
        if(a[i]!=a[i-1])
d+=(a[i]-a[1])/b;
if(d>c){
    cout<<i-1;
    return 0;
}
}
cout<<n;
return 0;
}
