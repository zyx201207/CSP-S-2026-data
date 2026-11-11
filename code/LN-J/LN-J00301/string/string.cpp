#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",std.in);
    freopen("string.out","w",std.out);
    long long a,b,c,d;
    char i,j,k;
    cin>>a>>b>>i>>c>>j>>d>>k;
    char s=b*i+c*j+d*k,x=d*k+c*j+b*i;
    if(s==x)
        cout<<0;
    else
        cout<<(b+c+d)/2;
    return 0;
 }
