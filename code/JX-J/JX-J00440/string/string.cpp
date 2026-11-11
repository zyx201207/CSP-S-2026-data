#include<bits/stdc++.h>
using namespace std;
long long n,ans,flag=1;
string s;
long long a;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int i=1;i<=a;i++){
            s+=c;
        }
    }
    for(int i=0;i<s.size();i++){
        if(s[i]!=s[s.size()+1-i])flag=0;
    }
    if(flag==1){
        cout<<0;
        return 0;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]==s[s.size()+1-i])continue;
        ans++;
    }
    if(ans%2!=0){
        cout<<ans/2+1;
    }else{
        cout<<ans/2;
    }
    return 0;
}
