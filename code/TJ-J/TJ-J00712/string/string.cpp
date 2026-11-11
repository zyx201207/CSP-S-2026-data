#include <bits/stdc++.h>
using namespace std;
long long n,a,cnt;
string s;
string b;
string s1;
int main(){
    freopen ("string.in","r",stdin);
    freopen ("string.out","w",stdout);
    cin >> n;
    for(long long i=0;i<=n;i++){
        cin>>a>>b;
    }
    for(long long i=0;i<a;i++){
        s=s+b;
    }
    for(long long i=s;length();i>=0;i++){
        s1[(s.length()-i)]=s[i]
    }
    for (long long i=0;i<=s.length();i++){
        if(s[i]==s[i]){
            cnt++;
        }
    }
    cout<<cnt/2-1;
    return 0;
}


