#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char b[200005];
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdont);
    cin>>n;
    long long o=0;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        o+=a[i];
    }
    long long sum=0;
    long long i=1,s=0;
    while(sum<o/2){
          sum+=a[i];
          s++;
          i++;
    }
    long long e;
    for(long long i=1;i<=s;i++){
        if(i==s){
            e=sum-o/2;
            a[i]-=e;
        }
        if(b[i]-1!=b[n]-1) ans+=a[i];
    }
    cout<<ans;
    return 0;
}
