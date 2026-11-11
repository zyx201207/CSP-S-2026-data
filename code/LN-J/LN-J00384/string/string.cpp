#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt=0;
    string s="";
    cin>>n;
    while(n--){
        long long m;
        char c;
        cin>>m>>c;
        while(m--) s+=c;
    }
    string s1=s;
    reverse(s1.begin(),s1.end());
    for(long long i=0;i<s.size();i++){
        if(s[i]!=s1[i]){
            cnt++;
            s1[i]=s[s.size()-1-i]=s[i];
        }
    }
    cout<<cnt;
    return 0;
}
