#include <bits/stdc++.h>
using namespace std;
int l;
void p(string s){
    long long ans=0;
    long long n=l/2;
    for(int i=0;i<n;i++){
        if(s[i]!=s[l-i-1]){
            ans++;
        }
    }
    cout<<ans;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s="";
    cin>>n;
    while(n--){
        int m;
        char c;
        cin>>m>>c;
        for(long long i=0;i<m;i++){
            s+=c;
        }
    }
    l=s.size();
    p(s);
    return 0;
}
