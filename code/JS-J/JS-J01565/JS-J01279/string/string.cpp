#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,m;
    string s,s2;
    cin>>n;
    if(n==1){
        cout<<'0';
        return 0;
    }
    for(int i = 1;i<=n;i++){
        cin>>m;
        cin>>s2;
        while(m--){
            s+=s2;
        }
    }
    long long len = s.length();
    long long mid = len/2,cnt = 0;
    for(int i = 0;i<mid;i++){
        if(s[i]!=s[len-i-1]){
            cnt++;
            s[len-1] = s[i];
        }
    }
    cout<<cnt<<"\n";
    return 0;
}
