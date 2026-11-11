#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin >> a >> c;
        for(int j=1;j<=a;j++){
            s[++cnt]=c;
        }
    }
    int ans=0;
    for(int i=1;i<=cnt;i++){
        if(s[i]!=s[cnt+1-i]){
            s[i]=s[cnt+1-i];
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
