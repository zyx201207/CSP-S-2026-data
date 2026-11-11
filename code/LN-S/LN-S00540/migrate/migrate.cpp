#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000010];
long long ans,s;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >>c>>t;
    while(t--){
        cin >>n>>d;
        ans=0;
        for(int i=1;i<=n;i++) cin >>a[i];
        s=abs(a[2]-a[1]);
        if(d<s) ans=0;
        else{
            ans=(1+d/s)*(d/s)/2;
        }
        cout <<ans<<endl;
    }
    return 0;
}
