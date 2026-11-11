#include <bits/stdc++.h>
using namespace std;
int n,l,ans;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int m;
        string c;
        cin>>m>>c;
        l+=m;
        for(int j=1;j<=m;j++){
            s+=c;
        }
    }
    for(int i=0;i<l/2;i++){
        if(s[i]!=s[l-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
