#include <bits/stdc++.h>
using namespace std;
long long n,a,t=1,cnt=0;
char s[2000000000],c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=t;j<=a+t-1;j++){
            s[j]=c;
        }t+=a-1;
    }for(int i=1;i<=t/2+1;i++){
        if(s[i]!=s[n-i+1]){
            cnt++;
        }
    }cout<<cnt;
    return 0;
}
