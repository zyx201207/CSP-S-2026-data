#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    int t=1,yg=0;
    for(int r=2,l=1;r<=n;r++){
        long long x=a[r]-a[r-1];
        yg+=(r-l)*x;
        while(yg>m){
            yg-=a[r]-a[l];
            l++;
        }
//        cout<<yg<<" "<<l<<" "<<endl;
        t=max(t,r-l+1);
    }
    cout<<t;
    return 0;
}
