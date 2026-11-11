#include<bits/stdc++.h>
using namespace std;
long long a[100010];
char c[100010];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(long long j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    long long l=s.size();
    long long cnt=0;
    for(long long i=0;i<l;i++){
        if(s[i]!=s[l+1-i])cnt++;
    }
    cout<<cnt/2;
    return 0;
}
