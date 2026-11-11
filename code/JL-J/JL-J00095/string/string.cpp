#include<bits/stdc++.h>
using namespace std;
long long n,a,b;
char c;
string s;
bool h(string s1){
    string s2;
    for(int i=s1.size()-1;i>=0;i--){
        s2+=s1[i];
    }
    if(s2==s1) return 1;
    else return 0;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    if(h(s)){
        cout<<0;
        return 0;
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            b++;
        }
    }
    cout<<b;
    return 0;
}
