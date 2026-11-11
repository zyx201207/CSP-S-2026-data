#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long a[N],ma;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(m==n){
        long long x,y;
        cin>>x>>y;
        ma=x&y;n-=2;
        while(n--){
            cin>>x;
            ma=ma&x;
        }
        cout<<ma;
        return 0;
    }
    ma=-12;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(m==1)ma=max(a[i],ma);
        else if(m==2&&i!=1){
            for(int j=1;j<i;j++){
                ma=max(ma,a[i]&a[j]);
            }
        }
    }
    cout<<ma;
    return 0;
}