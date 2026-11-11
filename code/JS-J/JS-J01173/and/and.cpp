#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
long long ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=0;i<m;i++){
        if(i==0){
            ans=a[n-i];
        }
        else{
            ans=ans&a[n-i];
        }
    }
    cout<<ans;
    return 0;
}
