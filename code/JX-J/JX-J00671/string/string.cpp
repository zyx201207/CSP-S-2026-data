#include<bits/stdc++.h>
using namespace std;
int n,a[200001],x;
string s;
char c[200001];
int main(){
    freopen("string.in","r",std.in);
    freopen("string.out","w",std.out);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i]){
            x++;
        }
    }
    cout<<x;
    return 0;
}
