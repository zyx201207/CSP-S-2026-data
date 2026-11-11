#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
string s;
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1,a;i<=n;i++){
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++)s+=c;
    }
    long long len=s.size();
    for(int i=0;i<len/2;i++)if(s[i]!=s[len-i-1])ans++;
    cout<<ans<<endl;
    return 0;
}
