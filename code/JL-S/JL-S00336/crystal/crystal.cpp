#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long a[N],b[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=a[i]+b[i-1];
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        for(int j=i+ans;j<=n;j++){
            if((a[j]*(j-i+1)-(b[j]-b[i-1]))<=m) ans=j-i+1;
            else{break;}
        }
    }
    cout<<ans;
    return 0;
}

