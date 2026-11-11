#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
char qq(long long m){
    long long n=0;
    int i=0;
    for(;;){
        n=n+a[i];
        i+=1;
        if(n>=m) break;

    }
    return c[i-1];
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long ad=0;
    int abss=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        ad+=a[i];
    }
    a[n+1]=1;
    c[n+1]=c[n];
    for(long long i=1;i<=ad/2;i++){
        if(qq(i)!=qq(ad-i+1)) abss++;
    }
    cout<<abss;
    return 0;
}
