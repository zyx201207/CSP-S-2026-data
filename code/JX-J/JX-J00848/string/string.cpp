#include<bits/stdc++.h>
using namespace std;
long long n,a[10000005],summ;
char b[10000005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        for(int j=1;j<=a[i];j++)s+=b[i];
    }
    int m=s.size();
    for(int i=0;i<m/2;i++){
        if(s[i]!=s[m-i-1])summ++;
    }
    cout<<summ;
    return 0;
}
