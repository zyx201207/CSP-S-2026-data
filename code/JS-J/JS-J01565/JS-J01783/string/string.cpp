#include<bits/stdc++.h>
using namespace std;
unsigned long long n, t, ans=0;
string s, s1;
char c;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin>>n;
    while(n--){
        cin>>t>>c;
        while(t--){
            s+=c;
        }
    }
    s1=s;
    reverse(s1.begin(), s1.end());
    long long m=s.size();
    for(long long i=0;i<m/2;i++){
        if(s[i]!=s1[i]) ans++;
    }
    cout<<ans;
    return 0;
}
