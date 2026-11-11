#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans=0;
    cin>>n;
    int a[n+5];
    char c[n+5];
    string s;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            s=s+c[i];
        }
    }
    for(int j=0;j<ceil(s.size()/2.0);j++){
        if(s[j]!=s[s.size()-1-j]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
