#include<bits/stdc++.h>
using namespace std;

long long n,m;

long long a[500001],l,r,ans;

bool cmp(long long x,long long y){
    return x<y;
}

int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;for(long long i=1;i<=n;i++)cin>>a[i];

    sort(a+1,a+1+n,cmp);

    long long qz=0;
    l=1;
    for(r=1;r<=n;r++){
        qz+=a[r];
        while((r-l+1)*a[r]-qz>m){
            qz-=a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }

    cout<<ans;

    return 0;

}
