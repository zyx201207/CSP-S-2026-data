#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        char b;
        cin>>a>>b;
        for(int j=0;j<a;j++){
            s+=b;
        }
    }
    if(s.length()%2==1){
        for(int i=0;i<s.length()/2+1;i++){
            if(s[i]==s[s.length()-i]){
                cout<<"0";
                return 0;
            }
            if(s[i]!=s[s.length()-i]) ans++;
        }
    }
    else{
        for(int i=0;i<s.length()/2;i++){
            if(s[i]==s[s.length()-i]){
                cout<<"0";
                return 0;
            }
            if(s[i]!=s[s.length()-i]) ans++;
        }
    }
    cout<<ans;
}
