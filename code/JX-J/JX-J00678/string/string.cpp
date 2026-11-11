#include <iostream>
using namespace std;
long long ans;
string s,s2;
int n,a;
char b;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        for(int i=0;i<a;i++)
            s+=b;
    }
    for(int i=0;i<s.size()/2;i++)
        s2+=s[i];
    for(int i=0;i<s.size()/2;i++){
        if(s[i+s.size()/2]!=s2[i])
            ans++;
    }
    cout<<ans;
}
