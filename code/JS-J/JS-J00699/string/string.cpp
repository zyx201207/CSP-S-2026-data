#include<bits/stdc++.h>
using namespace std;
string s;
long long zdgys(long long x,long long y){
    if(y%x==0) return x;
    else{
        int z=1;
        for(int i=2;i<x;i++){
            while(x%i==0&&y%i==0){
                x/=i;
                y/=i;
                z*=i;
            }
        }
        return z;
    }
}
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    s+=' ';
    long long sum=0,b=1;
    long long a[200005];
    char c[200005];
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
    }
    for(int i=2;i<=n;i++){
        b=zdgys(min(a[i],a[i-1]),max(a[i],a[i-1]));
    }
    for(int i=1;i<=n;i++){
        a[i]/=b;
        sum+=a[i];
        for(long long j=1;j<=a[i];j++) s+=c[i];
    }
    long long cnt=0;
    for(long long i=1;i<=sum/2;i++){
        if(s[i]!=s[sum+1-i]) cnt++;
    }
    cout << cnt*b << endl;
return 0;
}
