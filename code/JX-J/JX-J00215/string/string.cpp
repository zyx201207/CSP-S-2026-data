#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt=0;
    string s="";
    cin>>n;
    for(int i=1;i<=n;i++){
        long long a;
        string c;
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    long long len=s.size();
    for(int i=0;i<len/2;i++){
        if(s[i]!=s[len-i-1])cnt++;
    }
    cout<<cnt;
    return 0;
}
