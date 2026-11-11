#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+5;
long long a[N];
char c[N];
char s[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long b=0;
    long long k=0;
    for(long long i=0;i<n;i++){
        cin>>a[i]>>c[i];
        b+=a[i];
        for(long long j=b;j<b+a[i];j++){
                k++;
            s[k]+=c[i];
        }

    }
    long long d=0,i,j;
    long long ans=0;
    if(b%2==1){
        d=b/2+1;
        i=d-1;
        j=d+1;
        for(;i>=0,j<=b;i--,j++){
            if(s[i]!=s[j]){
              ans++;
            }
        }
    }
    else{
        d=b/2;
        i=d;
        j=d+1;
        for(;i>=0,j<=b;i--,j++){
            if(s[i]!=s[j]){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
