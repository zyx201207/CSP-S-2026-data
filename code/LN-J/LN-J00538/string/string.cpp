#include <bits/stdc++.h>
using namespace std;
string y;
long long n,a[200000],b,cnt,n2;
char c[200000],z[200000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }

    for(long long i=0;i<n;i++){
        for(long long j=0;j<a[i];j++){
            z[cnt]=c[i];
            cnt++;
        }
    }
    for(int i=0;i<=(cnt-1)/2;i++){
        if(z[i]!=z[cnt-i-1]){
            b++;
        }
    }
    cout<<b;
    return 0;
}
