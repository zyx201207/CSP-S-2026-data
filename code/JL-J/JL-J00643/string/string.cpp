#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
    long long n,t=0,a;
    char b;
    string s="",q="";
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        for(int j=1;j<=a;j++){
            s=s+b;
        }
    }
    int l=s.size();
    for(int i=l-1;i>=0;i--){
        q=q+s[i];
    }
    if(s==q) cout<<0;
    else{
        for(int i=0;i<=l-1;i++){
            if(s[i]!=q[i]){
                t++;
            }
        }
        cout<<t/2;
    }


    return 0;
}
