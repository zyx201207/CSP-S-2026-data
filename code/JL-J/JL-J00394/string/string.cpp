#include<bits/stdc++.h>
#define int long long
using namespace std;
string a;
int n,ans=0;
set<string> st;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int b;string s;
        cin>>b>>s;
        st.insert(s);
        for(int i=1;i<=b;i++) a+=s;
    }
    if(st.size()==1){
        cout<<0;
        return 0;
    }
    for(int i=0;i<a.size()/2;i++){
        if(a[i]==a[a.size()-1-i]) continue;
        ans++;
    }
    cout<<ans;
    return 0;
}
