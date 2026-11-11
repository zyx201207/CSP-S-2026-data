#include<bits/stdc++.h>
using namespace std;
vector<char> s;
long long n,m=0,v=0;
void AC(){
    long long l=0,r=m-1;
    while(l<=r){
        if(s[l]!=s[r]) v++;
        l++;
        r--;
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long a;
        char c;
        cin>>a;
        cin>>c;
        m+=a;
        while(a--){
            s.push_back(c);
        }
    }
    AC();
    printf("%lld",v);
    return 0;
}
