#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,b=0,l=0;
    char c;
    string s;
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a;
        cin>>c;
        for(long long j=b;j<b+a;j++){
            s[j]=c;
            l++;
        }
        b+=a;
    }
    long long solve=0;
    for(int i=0;i<=l/2;i++){
        if(s[i] != s[l-1-i]){
            solve++;
        }
    }
    cout<<solve;
    return 0;
}
