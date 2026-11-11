#include<bits/stdc++.h>
using namespace std;
const long long N=1E5*5;
long long a[N],b[N],mx=-1,c;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
            cin>>a[i];
            c+=a[i];
    }
    c/=n;
    sort(a,a+n+1);
    for(int i=1;i<=N;i++) b[a[i]]++;
    for(int i=1;i<=n;i++) if(b[i]>mx) mx=b[i];
    cout<<mx;
    return 0;
}
