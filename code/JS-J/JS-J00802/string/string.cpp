#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,ans;
    char c;
    string s="/0";
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    int txt=s.length();
    for(int i=0;i<=txt/2;i++){
        if(s[i]!=s[txt-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
