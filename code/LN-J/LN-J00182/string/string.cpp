#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int L,a[200005],ans=0;
    char b[200005];
    string s;
    long long n;
    cin>>L;
    for(int i=0;i<L;i++){cin>>a[i]>>b[i];n+=a[i];}
    for(long long i=0;i<n;i++){for(long long j=0;j<a[i];j++){s+=b[i];}}
    for(long long i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1]){
            ans++;
        }
    }
    cout<<ans;
}

