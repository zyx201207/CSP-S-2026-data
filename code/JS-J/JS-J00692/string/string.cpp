#include <bits/stdc++.h>
using namespace std;
long long n,a[200010],ans,l;
char c[2000000010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[l+1];
        for(int j=l+2;j<=l+1+a[i];j++){
            c[j]=c[l+1];
        }
        l+=a[i];
    }
    for(int i=1;i<=l/2.0;i++){
        if(c[i]!=c[l-i+1]) ans++;
    }
    cout << ans;
    return 0;
}
