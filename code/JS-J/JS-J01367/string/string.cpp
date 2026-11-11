#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s = "";
    int a,t = 0,cnt = 0;
    char c;
    for(int i = 1;i<=n;i++){
        cin>>a>>c;
        for(int j = 1;j<=a;j++){
            s+=c;
            t++;
        }
    }
    for(int i = 0;i<t/2;i++){
        if(s[i] != s[t-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
}
