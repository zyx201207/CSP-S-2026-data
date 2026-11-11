#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000086];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        char c;
        cin>>a[i];
        cin>>c;
        for(int j=1;j<=a[i];j++){
            s+=c;
        }
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
