#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s=" ";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){//68pts
        int x;
        char c;
        cin>>x>>c;
        for(int j=1;j<=x;j++)s+=c;
    }
    int len=s.size()/2;
    for(int i=1;i<=len;i++){
        if(s[i]!=s[s.size()-i])ans++;
    }
    cout<<ans;
    return 0;
}
