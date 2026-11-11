#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s,s1;
    long long n;
    cin>>n;
    for(int i=0;i<n;i++){
        long long x;
        string k;
        cin>>x>>k;
        for(long long j=1;j<=x;j++){
            s+=k;
        }
    }
    for(long long i=1;i<(long long)s.size();i--){
        s1+=s[i];
    }
    long long cnt=0;
    if(s.size()%2==0){
        for(long long i=0;i<(long long)s.size()/2;i++){
            if(s[i]!=s1[i])cnt++;
        }
    }
    else{
        for(long long i=0;i<(long long)s.size()/2-1;i++){
            if(s[i]!=s1[i])cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
