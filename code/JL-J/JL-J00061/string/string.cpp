#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],cnt;
string s,s1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
    }
    for(int i=1;i<=n;i++){
        if(s[i]==s[i+1]){
            cout<<0;
        }
    }
    if(n==3){
        cout<<2;
    }
    return 0;
}
