#include<bits/stdc++.h>
using namespace std;

long long n,x,l,ans;

int main(){
    freopen("string.in","r",stdin);
    char c;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>c;
        for(int j=1;j<=x;j++) s+=c;
    }
    l=s.size();
    for(int i=0;i<=l/2;i++)
        if(s[i]!=s[l-i-1]) ans++;
    cout<<ans;
    freopen("string.out","w",stdout);
    return 0;
}
