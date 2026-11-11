#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans=0;
    string s;
    cin >> n;
    for(int i=1;i<=n;i++){
        long long a;
        char c;
        cin >> a >> c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    long long l=s.size();
    s=' '+s;
    for(int i=1;i<=l/2;i++){
        if(s[i] != s[l+1-i]){
            s[l+1-i]=s[i];
        ans++;
        }
    }
    cout << ans;
    return 0;
}
