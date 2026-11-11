#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n=0,m=0,mx=-1e15-10,need=0,b=0;
    long long a[500050];
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(long long i=0;i<n;i++){
        for(long long j=0;j<i;j++){
            need+=a[i]-a[j];
            b++;
        }
        b+=1;
        if(need<=m){
            mx=max(mx,b);
        }
        b=0;
        need=0;

    }
    cout<<mx;
    return 0;
}
