#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a;
    char c;
    string s="";
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int i=1;i<=a;i++){
            s+=c;
        }
    }
    long long cnt=0;
    for(int i=0;i<s.length()/2;i++){
        if(s[i]!=s[s.length()-i-1]){cnt++;}
    }
    cout<<cnt;
    return 0;
}
