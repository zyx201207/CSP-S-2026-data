#include <iostream>
#include <cmath>
using namespace std;
long long a[105];
char b[105];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> b[i];
    }
    string s="",f="";
    for(int i=1;i<=n;i++) for(int j=1;j<=a[i];j++) s+=b[i];
    for(int i=n;i>=1;i--) for(int j=1;j<=a[i];j++) f+=b[i];
    int cnt = 0;
    for(int i=1;i<=n;i++) if(s[i]!=f[i]) cnt++;
    cout << cnt/2;
    return 0;
}