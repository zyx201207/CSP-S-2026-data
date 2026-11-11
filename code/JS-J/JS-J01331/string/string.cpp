#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a;
    long long cnt=0;
    char c;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int i=1;i<=a;i++)
            s+=c;
    }
    string f=s;
    reverse(f.begin(),f.end());
    if(f==s){
        cout<<0;
        return 0;
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1])
            cnt++;
    }
    cout<<cnt;
    return 0;
}
