#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
string b[10000005],c[200005];
long long ans,tool;
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>a[i]>>c[i];
        for(long long j = tool; j < tool + a[i]; j++) b[j] = c[i];
        tool += a[i];
    }
    for(long long i = 0; i < tool / 2; i++) {
        tool--;
        if(b[i] != b[tool]) ans++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
