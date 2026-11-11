#include<bits/stdc++.h>
using namespace std;
string s;
char c;
int n,a;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        for(int j=0;j<a;j++)
            s+=c;
    }
    for(int i=0;i<s.size()/2;i++)
        if(s[i]!=s[s.size()-i-1])
            ans++;
    cout<<ans<<"\n";
    return 0;
}
