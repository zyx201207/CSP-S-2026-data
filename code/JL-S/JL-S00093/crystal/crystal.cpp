#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long n,m;
long long a[N];
long long diff[N];
long long ans=1;
long long l=1,r=2;
long long maxx=-1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n-1;i++){
        diff[i]=a[i+1]-a[i];
    }
    while(l<=r&&r<=n){
        if(l==r){
            r++;
        }else if(m-(r-l)*(diff[r-1])>=0){
            m-=(r-l)*(diff[r-1]);
            maxx=max(r-l+1,maxx);
            r++;
            //cout<<l<<" "<<r<<" "<<maxx<<endl;
        }else{
            m+=a[r-1]-a[l];
            ++l;
            maxx=max(r-l+1,maxx);
            //cout<<l<<" "<<r<<" "<<maxx<<endl;
        }
    }cout<<maxx;
    return 0;
}

