#include <bits/stdc++.h>
using namespace std;
long long a,b,e,n;
char c;
string d;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a;
    for (long long i=1;i<=a;i++){
        cin>>b>>c;
        e+=b;
        for (long long j=1;j<=b;j++){
            d=d+c;
        }
    }
    for (long long i=0;i<e/2;i++){
        if (d[i]!=d[e-i-1]){
            n+=1;
        }
    }
    cout<<n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
