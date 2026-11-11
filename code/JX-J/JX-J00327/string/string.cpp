#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i] >> b[i];
    string s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=b[i];
        }
    }
    long long ans=0,i=0;
    for(int j=s.length();j>=0;j--){
        if(i==j)break;
        if(s[i]!=s[j]){
            ans++;
            i++;
        }
    }
    cout << ans;
    return 0;
}
