#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    long long n1=n/2;
    char a;
    long long i=0;
    long long x;
    long long sum=0
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>a;
        for(int j=1;j<=x;j++) s+=a;
    }
    while(n1--)
        if(s[i]!=s[n-1-i]) sum++;
        i++;
    }
    cout<<sum;
    return 0;
}
