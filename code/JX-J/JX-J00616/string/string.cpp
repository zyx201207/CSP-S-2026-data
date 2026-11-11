#include <bits/stdc++.h>
using namespace std;
string s;
struct {
    long long a;
    char c;
}z[200000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,siz=0,sum=0;
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>z[i].a>>z[i].c;
    }
    for(long long i=0;i<n;i++){
        for(long long j=0;j<z[i].a;j++){
            siz++;
            s[j]=z[i].c;
        }
    }
    for(long long i=0;i<siz/2;i++){
        if(s[i]!=s[siz-1-i])sum++;
    }
    cout<<sum;
    return 0;
}
