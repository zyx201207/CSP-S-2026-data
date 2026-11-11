#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,sum=0;
    string s;
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long a;
        char c;
        cin>>a>>c;
        for(long long j=1;j<=a;j++){
            s+=c;
        }
    }
    long long x=s.size();
    long long k=x-1;
    for(long long i=0;i<x/2;i++){
        if(s[i]!=s[k]) sum++;
        k--;
    }
    cout<<sum;
    return 0;
}
