#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long cnt;
    string s,s1;
    int a[200005];
    string b[200005];
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        cin >> b[i];
        cnt+=a[i];
        for(int j=1;j<=a[i];j++){
            s += b[i];
        }
    }
    for(int i=cnt-1;i>=0;i--){
        s1+=s[i];
    }
    int ans = cnt;
    for(int i=0;i<=cnt-1;i++){
        if(s[i] == s1[i])ans--;
    }
    cout << ans/2;

    return 0;
}
