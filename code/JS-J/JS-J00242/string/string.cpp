#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
unsigned long long cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    unsigned long long n;
    unsigned long long a;
    char c;
    string s;
    cin>>n;
    unsigned long long cn;
    char h;
    for(unsigned long long i=0;i<n;i++){
        cin>>a>>c;
        while(a--){
            s+=c;
        }
    }
    for(unsigned long long i=0;i<s.size();i++){
        if(s[i]!=s[s.size()-i-1]){
            cnt++;
        }
    }
    cout<<cnt/2;
    return 0;
}
