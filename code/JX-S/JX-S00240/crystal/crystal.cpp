#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],l,t,b[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        t+=l*(a[i]-a[i-1]);
        l++;
        while(t>m){
            t=t-(a[i]-a[i-l+1]);
            l--;
        }
        b[i]=l;
    }
    long long ma=0;
    for(int i=1;i<=n;i++){
        if(b[i]>ma)ma=b[i];
    }
    cout<<ma;
    return 0;
}
