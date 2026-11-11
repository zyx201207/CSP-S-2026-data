#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string s="";
    long long l=0;
    for(int i=1;i<=n;i++) {
        cin >> a[i] >> c[i];
        for(int j=1;j<=a[i];j++) {
            s+=c[i];
        }
        l+=a[i];
    }
    long long ans=0;
    for(int i=0;i<=l/2-1;i++) {
        long long r=l-i-1;
        if(s[i]!=s[r]) ans++;
    }
    cout << ans;
    return 0;
}