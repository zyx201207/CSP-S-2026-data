#include <bits/stdc++.h>
using namespace std;
long long n,x,m,cnt = 0;
char a;
char s[2000000005];
int main(){
    freopen("string2.in","r",stdin);
    freopen("string2.out","w",stdout);
    scanf("%lld",&n);
    for(long long i = 1;i<=n;i++){
        cin>>x;
        cin>>a;
        for(long long j = 0;j<x;j++){
            s[j+m]=a;
        }
        m+=x;
    }
    for(int i = 0,j = m-1;i<j;i++,j--){
        if(s[i]!=s[j]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
