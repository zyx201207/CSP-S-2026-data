#include <bits/stdc++.h>
using namespace std;
long long n,t;
long long num,ans;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>num>>c;
        for(long long j=0;j<num;j++) s+=c;
    }
    for(long long i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
