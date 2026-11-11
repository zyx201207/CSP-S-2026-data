#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="\0";
    int a,n,x=0;
    char c;
    for(int i=1;i<=n;i++){
        cin>>a;
        cin>>c;
        for(int j=1;j<=a;j++){
            s=s+c;
        }
    }
    int l=s.length()/2-1,l0=s.length()-1;
    cout<<l0<<" "<<l<<endl;
    for(int i=0;i<=l;i++){
        if(s[i]!=s[l0-i])x++;
    }
    cout<<x;
    return 0;
}
