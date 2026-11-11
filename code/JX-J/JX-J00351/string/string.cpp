#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string S="";
    for(int i=1;i<=n;i++){
        int x;
        char y;
        while(x--){
            S+=y;
        }
    }
    int c=0,l=S.length();
    for(int i=0;i<l/2;i++){
        if(S[i]!=S[l-i+1])c++;
    }
    cout<<c;
    return 0;
}
