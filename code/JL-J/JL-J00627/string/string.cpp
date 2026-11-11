#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,p=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        char c;
        cin>>a>>c;
        p+=a;
        for(int j=0;j<a;j++){
            s=s+c;
        }
    }
    int q=0;
    for(int i=0;i<p/2;i++){
       if(s[i]!=s[p-i-1]){
            q++;
       }
    }
    cout<<q;



    return 0;
}
