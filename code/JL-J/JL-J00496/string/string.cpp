#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n1,a,l=0,b=0;
    char c;
    cin>>n1;
    string n;
    for(long long i=1;i<=n1;i++){
        cin>>a>>c;
        l+=a;
        for(long long j=1;j<=a;j++){
            n+=c;

        }
    }
    if(n[0]!=n[l-1])b++;
    for(long long i=1;i<l-1;i++){

        if(i!=0&&n[i]!=n[l-i]){

            n[i]=n[l-i];
            n[l-i]=n[i];
            ++b;

       }}
    cout<<b;
    return 0;
}
