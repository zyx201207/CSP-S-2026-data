#include <bits/stdc++.h>
using namespace std;
long long n,ans;
string s,s1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        int a;
        char c;
        cin>>a>>c;
        for(int i=1;i<=a;i++){
            s+=c;
        }
    }
    for(int i=0;i<s.size();i++){
        for(int j=size();j>=0;j--){
            if(s[i]==s[j])
                ans=0;
            }
    }
    cout<<0;
    return 0;
}
