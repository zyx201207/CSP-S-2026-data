#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0,x=1;
    long long L=0;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        long long a;
        char c;
        cin>>a>>c;
        L+=a;
        for(int j=1;j<=a;j++){
            s[x]=c;
            x++;
        }
    }
    for(int i=1;i<=L/2;i++){
        if(s[i]!=s[L+1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
