#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000];
int s[50];
int ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ans=max(a[i],ans);
    }
    cout<<ans;
    return 0;
}
