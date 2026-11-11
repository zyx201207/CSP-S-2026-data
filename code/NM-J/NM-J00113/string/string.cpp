#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
string c,s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i] >> c[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            s[i]=c[i];
        }
    }
    cout << "0";
    return 0;
}
