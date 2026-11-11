#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,l=0,x=0;
    char c;
    string s="";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        for(int j=0;j<a;j++){
            s=s+c;
        }
        l+=a;
    }
    for(int i=0;i<l/2;i++){
        if(s[i]!=s[l-1-i]) x++;
    }
    cout<<x;
    return 0;
}
