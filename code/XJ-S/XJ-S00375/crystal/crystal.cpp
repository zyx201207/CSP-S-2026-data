#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],maxn,minn=1e18;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
minn=min(minn,a[i]-a[i-1]);
}
sort(a+1,a+n+1);
for(int i=1;i<=n;i++)
{
    b[i]=b[i-1]+a[i];
}
if(minn>m){
cout<<0;
return 0;
}
{
    cout<<0;return 0;
}
if(a[n]*(n-1)-b[n-1]<=m){
    cout<<n;
    return 0;
}

for(int i=1;i<n;i++)
{   long long cnt=0,sum=a[i];
for(int j=i+1;j<=n;j++){
    if((j-i)*a[j]-sum<=m){
        cnt++;
        sum+=a[j];
    }

}


maxn=max(maxn,cnt);

}
cout<<maxn+1;
return 0;
}

