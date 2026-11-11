#include <bits/stdc++.h>
using namespace std;
int n,a[100005];
long long ans=0;
char c[100005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >>n;
    for(int i= 1;i <= n;i++){
        cin >> a[i] >> c[i];
    }
    int l=1,r=n;
    while(l<r){
        int nm = min(a[l],a[r]);
        if(c[l]!=c[r])  ans += nm;
        a[l]-=nm;
        a[r]-=nm;
        if(a[l]==0) l++;
        if(a[r]==0) r--;
    }
    cout << ans;
    return 0;
}
