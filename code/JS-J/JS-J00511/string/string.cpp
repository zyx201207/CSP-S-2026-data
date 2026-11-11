#include<bits/stdc++.h>
using namespace std;
unsigned long long n,x[200005],c;
char a[200005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>a[i];
        for(int j=0;j<x[i];j++) s+=a[i];
    }
    for(int i=0;i<(s.size()%2==0?s.size()/2:(s.size()-1)/2);i++) if(s[i]!=s[s.size()-1-i]) c++;
    cout<<c;
    return 0;
}
