#include <bits/stdc++.h>
using namespace std;
long long a[500005],qz[500005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        qz[i]=qz[i-1]+a[i];
    }
    int mn=1;
    for(int i=1;i<=n;i++){
        int l=i+mn,r=n;
        while(l<=r){
            int j=(l+r)/2;
            if((j-i+1)*a[j]<=m+qz[j]-qz[i-1]){
                mn=max(mn,j-i+1);
                l=j+1;
            }
            else{
                r=j-1;
            }
        }
    }
    cout<<mn<<'\n';
    return 0;
}
