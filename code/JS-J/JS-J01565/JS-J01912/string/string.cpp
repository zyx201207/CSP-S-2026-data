#include<bits/stdc++.h>
using namespace std;
string f(string s){
    string t="";
    for(int i=s.length()-1;i>=0;i--){
        t+=s[i];
    }
    return t;
}
int main(){
//    freopen("string.in","r",stdin);
//    freopen("string.out","w",stdout);
    string s;
    long long n,a;
    char c;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    string t=f(s);
    int mid=ceil(s.length()/2.0);
    int ans=0;
    for(int i=0;i<mid;i++){
        if(s[i]!=t[i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
