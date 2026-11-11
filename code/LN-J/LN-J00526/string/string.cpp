#include <bits/stdc++.h>
using namespace std;
string s,c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long n,a,mis=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        cin>>c;
        for(int j=0;j<a;j++){
            s+=c;
        }
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            mis++;
        }
    }
    cout<<mis;
    return 0;
}
