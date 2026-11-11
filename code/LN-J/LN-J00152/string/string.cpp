#include<iostream>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        char a;
        cin>>a;
        for(int j=1;j<=x;j++){
            s+=a;
        }
    }
    int ans=0;
    for(int i=0;i<s.length();i++){
        if(s[i]!=s[s.length()-i-1]) ans++;
    }
    cout<<ans/2;
    return 0;
}
