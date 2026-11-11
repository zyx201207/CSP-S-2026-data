#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long mid=0;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long l=1,r=1;
    long long maxx=1;
    long long lon=1;
    long long need=0;
    while(l<n&&r<n){
        if(need+((r-l+1)*(a[r+1]-a[r]))<=m){
            lon++;
            need+=(r-l+1)*(a[r+1]-a[r]);
            r++;
        }
        else{
            maxx=max(maxx,lon);
            need+=(r-l+1)*(a[r+1]-a[r]);
            r++;
            lon++;
            while(need>m&&l<r){
                need-=a[r]-a[l];
                l++;
                lon--;
            }
        }
    }
    maxx=max(maxx,lon);
    cout<<maxx<<endl;
    return 0;
}
