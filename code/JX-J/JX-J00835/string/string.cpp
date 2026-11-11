#include<bits/stdc++.h>
using namespace std;
long long a[100000010];
char b[1000000010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,m,sum=0;
    string c;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=a[i];j++){
            c+=b[i];
        }
    }
    m=c.size();
    for(long long i=0;i<m/2;i++){
        if(c[i]!=c[m-1-i]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
