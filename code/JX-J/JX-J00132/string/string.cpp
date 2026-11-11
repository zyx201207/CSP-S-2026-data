#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,l=0,s=0;
    char c;
    string S="";
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        l+=a;
        for(int j=1;j<=a;j++)S+=c;
    }
    for(int i=0;i<l/2;i++){
        if(S[i]!=S[l-1-i]){
            s++;
        }
    }
    cout<<s;



    return 0;
}
