#include<bits/stdc++.h>
using namespace std;
int f(string s){
    string fs=s;
    reverse(s.begin(),s.end());
    return s==fs;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    for(long long i=1;i<=n;i++){
        long long x;
        char c;
        cin>>x>>c;
        for(long long j=1;j<=x;j++){
            s+=c;
        }
    }
    long long cnt=0;
    while(1){
        if(f(s)==1){
            cout<<cnt;
            break;
        }
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=s[s.size()-1-i]){
                s[i]=s[s.size()-1-i];
                cnt++;
                break;
            }
        }
    }
    return 0;
}
