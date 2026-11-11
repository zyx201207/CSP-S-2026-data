#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxn,cnt,b,c;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n>5000){
        c=a[2]-a[1];
        cout<<min(1+(m/c),n);
        return 0;
    }
    for(int i=2;i<=n;i++){
        cnt=1;
        b=m;
        for(int j=i-1;j>=1;j--){
            if(a[i]-a[j]<=b){
                cnt++;
                b-=(a[i]-a[j]);
            }
            else break;
        }
        maxn=max(maxn,cnt);
    }
    cout<<maxn;
    return 0;
}
