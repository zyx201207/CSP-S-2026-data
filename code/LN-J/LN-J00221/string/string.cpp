#include<bits/stdc++.h>
using namespace std;
long long n,ans,cnt;
long long a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];

    }
    for(int i=1;i<=n/2;i++){

        if(c[n-i+1]!=c[i]){
            ans+=a[i];
        }
    }
    cout<<ans;
    return 0;
}
