#include<bits/stdc++.h>
using namespace std;
string s;
int n;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int cnt;
        char c;
        cin>>cnt>>c;
        for(int j=1;j<=cnt;j++){
            s+=c;
        }
    }
    string s1=s;
    reverse(s1.begin(),s1.end());
    for(int i=0;i<s.size();i++){
        if(s[i]!=s1[i]) ans++;
    }
    cout<<ans/2;
    return 0;
}
