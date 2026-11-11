#include <bits/stdc++.h>
using namespace std;
int n;
string s,s1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long sum=0;
    for(int i=1;i<=n;i++){
        long long a;
        cin>>a;
        char b;
        cin>>b;
        for(long long j=0;j<a;j++){
            s+=b;
        }
    }
    for(long long i=0;i<s.size();i++){
        s1[i]=s[s.size()-i-1];
    }
    for(long long i=0;i<(s.size()/2);i++){
        if(s1[i]!=s[i]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}