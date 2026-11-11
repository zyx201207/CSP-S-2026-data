#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a[200005];
    char b[200005];
    long long n;
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i] >> b[i];
    }
    string s;
    long long ans=0;
    for (int i=1,j=n;j>=i;)
    {
        if (b[i]!=b[j]) ans++;
        a[i]--;
        a[j]--;
        if (a[i]<=0) i++;
        if (a[j]<=0) j--;
    }
    cout << ans;
    return 0;
}
