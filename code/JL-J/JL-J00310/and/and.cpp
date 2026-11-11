#include <bits/stdc++.h>
using namespace std;
int a[200005];
long long n,k;
bool cmp(int b,int c){
    return b>c;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int ans=a[1];
    for(int i=2;i<=k;i++){
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}
