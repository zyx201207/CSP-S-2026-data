#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a;
    long long ans=0;
    string s=" ";
    char a1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>a1;
        for(int j=1;j<=a;j++){
            s+=a1;
        }
    }
    for(int i=1;i<=s.size()/2+1;i++){
        if(s[i]!=s[s.size()-i]){
            ans++;
            s[s.size()-i]=s[i];
        }
    }
    cout<<ans;
    return 0;
}
