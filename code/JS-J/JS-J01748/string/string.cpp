

#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int a[MAXN];
char c[MAXN];
int n,l=0;
string s="";
int main(){
    freopen("string.in","r".stdin);
    freopen("string.out","w".stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        l+=a[i];
        s+=c[i]*a[i];
    }
    int cnt=0;
    for(int i=0;i*2<=l;i++){
        if(s[i]!=s[l-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
