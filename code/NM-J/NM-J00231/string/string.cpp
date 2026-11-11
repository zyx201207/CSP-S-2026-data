#include<bits/stdc++.h>
using namespace std;
string s,t;
int a[200005],l,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
        l+=a[i];
        for(int j=1;j<=a[i];j++){
            t+=s[i];
        }
    }
    t=" "+t;
    for(int i=1;i<=(l+1)/2;i++){
        if(t[i]!=t[l-i+1])ans++;
    }
    cout<<ans;

    return 0;
}
