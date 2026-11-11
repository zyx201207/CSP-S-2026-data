#ifndef STRING_CPP_INCLUDED
#define STRING_CPP_INCLUDED
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int l=0;
    string s;
    for (int i=1;i<=n;i++){
        int x;
        char c;
        cin>>x>>c;
        s+=x*c;
        l+=x;
    }
    int m=l-1;
    l/=2;
    int cnt=0;
    for (int i=0;i<l;i++){
        if (s[i]!=s[m-i]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;

}

#endif // STRING_CPP_INCLUDED
