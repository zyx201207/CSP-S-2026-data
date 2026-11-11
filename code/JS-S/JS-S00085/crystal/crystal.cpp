#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m,a[N],used[N],b[N];
int main(){
    freopen("r",crystal.in);
    freopen("w",crystal.out);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i]+b[i-1];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        int cnt=0;
        cnt=i*a[i]-b[i];
        if(cnt<=m){
            used[i]=i;
        }else{
            cout<<used[i-1];
            return 0;
        }
    }
    return 0;
}
