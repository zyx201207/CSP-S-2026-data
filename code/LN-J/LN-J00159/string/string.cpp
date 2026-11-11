#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
int a,n;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a>>c;
        for(int j = 0;j<a;j++){
            s+=c;
        }
    }
    string t = s;
    reverse(t.begin(),t.end());
    int ans = 0;
    for(int i = 0;i<s.size();i++){
        if(s[i]!=t[i]) ans++;
    }
    cout<<ans/2;
}
