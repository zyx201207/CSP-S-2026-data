#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,c=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char b;
        cin>>a>>b;
        c+=a;
        for(int j=c;j<=a;j++){
            s[j]=b;
        }
    }cout<<0;
    return 0;
}
